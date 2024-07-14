// Package embeds a SQLite build that includes sqlite-vec into your application.
//
// Importing package embed initializes the [sqlite3.Binary] variable
// with an appropriate build of SQLite:
//
//	import _ "github.com/asg017/sqlite-vec-ncruces-bindings"
package embed

import (
	_ "embed"
	"github.com/ncruces/go-sqlite3"
)

//go:embed sqlite3.wasm
var binary []byte

func init() {
	sqlite3.Binary = binary
}
