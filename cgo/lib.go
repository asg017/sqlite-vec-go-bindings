package vec

// #cgo CFLAGS: -DSQLITE_CORE
// #cgo linux LDFLAGS: -lm
// #include "sqlite-vec.h"
//
import "C"
import (
	"bytes"
	"context"
	"database/sql"
	"encoding/binary"
	"fmt"
	"reflect"
	"unsafe"

	sqlite3 "github.com/mattn/go-sqlite3"
)

// Serializes a float32 list into a vector BLOB that sqlite-vec accepts.
func SerializeFloat32(vector []float32) ([]byte, error) {
	buf := new(bytes.Buffer)
	err := binary.Write(buf, binary.LittleEndian, vector)
	if err != nil {
		return nil, err
	}
	return buf.Bytes(), nil
}

// Loads the sqlite-vec extension into the given database connection.
// The connection must be a *sqlite3.SQLiteConn from github.com/mattn/go-sqlite3.
// Beware! this unsafe and reflection to access the underlying C pointer.
func Load(db *sql.DB) error {
	conn, err := db.Conn(context.Background())
	if err != nil {
		return err
	}
	defer conn.Close()
	return conn.Raw(func(driverConn interface{}) error {
		sc, ok := driverConn.(*sqlite3.SQLiteConn)
		if !ok {
			return fmt.Errorf("not sqlite3 conn")
		}
		dbVal := reflect.ValueOf(sc).Elem().FieldByName("db")
		dbPtr := unsafe.Pointer(dbVal.Pointer())
		raw := (*C.sqlite3)(dbPtr)
		rc := C.sqlite3_vec_init(raw, nil, nil)
		if rc != C.SQLITE_OK {
			return fmt.Errorf("sqlite3_vec_init failed: %d", int32(rc))
		}

		return nil
	})
}
