/*
 *  \File: procdriver.h
 *
 *  \Owner: ffkeff
 *
 *  \Created at 09-08-2024
 *
 */

#ifndef PROCDRIVER_H
#define PROCDRIVER_H

#include "../include/ftop_types.h"
#include "../include/process.h"

#define PROCDIR "/proc"

/************** PROC ROOT ENTRY LIST ****************/

struct
ProcEntryList {
    struct ProcEntry    *head;
    struct ProcEntry    *tail;
};

// Create new instance ProcEntryList
static struct ProcEntryList *
proc_entry_list_init(void);

static struct ProcEntry *
proc_entry_push(struct ProcEntry *entry, struct ProcEntryList *list);

// Unsafe
#define proc_entry_list_foreach(entry, entry_list) \
for (entry = entry_list->head;                     \
     entry != entry_list->tail;                    \
     entry = entry->next)

static void
proc_entry_pop(struct ProcEntryList *list);

static void
proc_entry_list_free(struct ProcEntryList *list);


/************** PROC ROOT OPERATIONS ***************/

struct ProcEntryList *
get_proc_entries(void);


/************** PROC INFO OPERATIONS ***************/
struct
    ProcessInfoOperations {
    char entry_name[MAX_FILE_NAME_LENGHT];
    void (*read_to) (const char *);
};
#endif /* procdriver.h */
