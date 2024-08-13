/*
 *  \File: procdriver.c
 *
 *  \Owner: ffkeff
 *
 *  \Created at 09-08-2024
 *
 */

#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#include "../include/procdriver.h"

static struct ProcEntryList *
proc_entry_list_init(void) {
    struct ProcEntryList    *list;

    list = (struct ProcEntryList*)malloc(sizeof (struct ProcEntryList));

    list->head = NULL;
    list->tail = NULL;

    return list;
}

static struct ProcEntry *
proc_entry_init(void) {
    static struct ProcEntry *entry;

    entry = (struct ProcEntry *)malloc(sizeof (struct ProcEntry));
    if (!entry) return NULL;

    memset(entry, 0, MAX_FILE_NAME_LENGHT);
    entry->type = Undefined;
    entry->next = NULL;
    entry->prev = NULL;

    return entry;
}

static struct ProcEntry *
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

static void
proc_entry_node_pop(struct ProcEntryList *list) {
    struct ProcEntry     *tmp;

    if (!list) return; //TODO

    tmp = list->tail;
    list->tail = tmp->prev;
    (void) free(tmp);
}

//memory leak!!!
void
proc_entry_list_free(struct ProcEntryList *list) {
    struct ProcEntry    *entry;

    proc_entry_list_foreach(entry, list) {
        (void) free(entry->prev);
    }

    (void) free(list);
}

struct ProcEntryList *
get_proc_entries(void) {
    DIR                     *dir;
    struct ProcEntryList    *list;
    struct dirent           *entry;

    dir = opendir(PROCDIR);
    if (!dir) return NULL;

    list = proc_entry_list_init();
    if (!list) {
        closedir(dir);
        return NULL;
    }

    while (NULL != (entry = readdir(dir))) {
        struct ProcEntry        *proc_entry;

        proc_entry = proc_entry_init();
        if (!proc_entry) {
            proc_entry_list_free(list);
            closedir(dir);
            return NULL;
        }

        strcpy(proc_entry->name, entry->d_name);

        if (is_process_id(entry->d_name)) {
            proc_entry->type = ProcessInfo;
        } else {
            //TODO
        }

        proc_entry_push(proc_entry, list);
    }

    closedir(dir);

    return list;
}


