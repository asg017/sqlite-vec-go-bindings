#ifndef SQLITE_VEC_H
#define SQLITE_VEC_H

#ifndef SQLITE_CORE
#include "sqlite3ext.h"
#else
#include "sqlite3.h"
#endif

#ifdef SQLITE_VEC_STATIC
  #define SQLITE_VEC_API
#else
  #ifdef _WIN32
    #define SQLITE_VEC_API __declspec(dllexport)
  #else
    #define SQLITE_VEC_API
  #endif
#endif

#define SQLITE_VEC_VERSION "v0.1.3-alpha.2"
#define SQLITE_VEC_DATE "2024-09-16T17:49:22Z+0000"
#define SQLITE_VEC_SOURCE "330f021216d0fd44d60212aaffab822b314822f2"

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
