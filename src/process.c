/*
 *  \File: process.c
 *
 *  \Owner: ffkeff
 *
 *  \Created at 11-08-2024
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/process.h"

i32 is_process_id(const char *name) {
    char *end;

    if (NULL == name || '\0' == *name) return 0;

    (void) strtol (name, &end, 10);
    if (name == end || '\0' != *end) return 0;

    return 1;
}

char *
get_full_path(i32 item) {
    char    *full_path;

    full_path = (char*) malloc (sizeof(char) * 2048);

    snprintf(full_path,
             MAX_FILE_NAME_LENGHT * PROCINFO_DIR_DEPTH,
             "%s/%d",
             PROCDIR,
             item);

    return full_path;
}

struct ProcEntryList *
proc_entry_list_init(void) {
    struct ProcEntryList    *list;

    list = (struct ProcEntryList*)malloc(sizeof (struct ProcEntryList));

    list->head = NULL;
    list->tail = NULL;

    return list;
}

struct ProcEntry *
proc_entry_init(void) {
    struct ProcEntry *entry;

    entry = (struct ProcEntry *)malloc(sizeof (struct ProcEntry));
    if (!entry) return NULL;

    memset(entry, 0, MAX_FILE_NAME_LENGHT);
    entry->type = Undefined;
    entry->next = NULL;
    entry->prev = NULL;

    return entry;
}

struct ProcEntry *
proc_entry_push(struct ProcEntry *entry, struct ProcEntryList *list) {
    if (!entry || !list) return NULL;

    if (NULL == list->head) {
        list->head = entry;
        list->tail = entry;
    } else {
        entry->prev = list->tail;

        list->tail->next = entry;
        list->tail = entry;
    }

    return entry;
}

static i32
proc_entry_node_pop(struct ProcEntryList *list) {
    struct ProcEntry     *tmp;

    if (!list) return -1;

    tmp = list->tail;
    list->tail = tmp->prev;
    (void) free (tmp);

    return 0;
}

i32
proc_entry_list_free(struct ProcEntryList *list) {
    struct ProcEntry    *entry;
    struct ProcEntry    *temp;

    if (!list) return -1;

    entry = list->head;

    while (entry != list->tail) {
        temp = entry;
        entry = entry->next;
        (void) free (temp);
    }

    (void) free (list);

    return 0;
}

struct ProcEntryList *
filter_entry_list(struct ProcEntryList *list, enum ProcEntryType filter) {
    struct ProcEntryList    *process_info_list;
    struct ProcEntry        *entry;

    process_info_list = proc_entry_list_init();

    proc_entry_list_foreach(entry, list) {
        if (entry->type == filter) proc_entry_push(entry, process_info_list);
    }

    return process_info_list;
}


