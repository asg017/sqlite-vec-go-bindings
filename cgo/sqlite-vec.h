#ifndef SQLITE_VEC_H
#define SQLITE_VEC_H

#include "sqlite3ext.h"

#ifdef SQLITE_VEC_STATIC
  #define SQLITE_VEC_API
#else
  #ifdef _WIN32
    #define SQLITE_VEC_API __declspec(dllexport)
  #else
    #define SQLITE_VEC_API
  #endif
#endif

#define SQLITE_VEC_VERSION "v0.1.2-alpha.10"
#define SQLITE_VEC_DATE "2024-09-13T00:32:15Z+0000"
#define SQLITE_VEC_SOURCE "deb14a9fcd4edaaeab4fa33ef457760a893b044f"

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
