#ifndef SQLITE_VEC_H
#define SQLITE_VEC_H

#include "sqlite3ext.h"

#define SQLITE_VEC_VERSION "v0.0.1-alpha.33"
#define SQLITE_VEC_DATE "2024-07-14T21:25:44Z+0000"
#define SQLITE_VEC_SOURCE "18e33edf143cafd881643965a559cd0259ab0666"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _WIN32
__declspec(dllexport)
#endif
int sqlite3_vec_init(sqlite3 *db, char **pzErrMsg,
                  const sqlite3_api_routines *pApi);

#ifdef _WIN32
__declspec(dllexport)
#endif
int sqlite3_vec_fs_read_init(sqlite3 *db, char **pzErrMsg,
                          const sqlite3_api_routines *pApi);


#ifdef __cplusplus
}  /* end of the 'extern "C"' block */
#endif

#endif /* ifndef SQLITE_VEC_H */
