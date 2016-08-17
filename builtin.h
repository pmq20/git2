#ifndef BUILTIN_H_4EA9A4B4
#define BUILTIN_H_4EA9A4B4

#include "common.h"

extern int cmd_hash_object(int argc, const char **argv, const char *prefix);
extern int cmd_receive_pack(int argc, const char **argv, const char *prefix);
extern int cmd_pack_objects(int argc, const char **argv, const char *prefix);
extern int cmd_unpack_objects(int argc, const char **argv, const char *prefix);

#endif /* end of include guard: BUILTIN_H_4EA9A4B4 */
