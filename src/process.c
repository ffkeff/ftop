/*
 *  \File: process.c
 *
 *  \Owner: ffkeff
 *
 *  \Created at 11-08-2024
 *
 */


#include <stdlib.h>
#include "../include/process.h"

i32 is_process_id(const char *name) {
    char *end;

    if (NULL == name || '\0' == *name) return 0;

    strtol(name, &end, 10);
    if (name == end || '\0' != *end) return 0;

    return 1;
}
