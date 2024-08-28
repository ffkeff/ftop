/*
 *  \File: process.h
 *
 *  \Owner: ffkeff
 *
 *  \Created at 11-08-2024
 *
 */

#ifndef PROCESS_H
#define PROCESS_H

#include "../include/ftop_types.h"

#define MAX_FILE_NAME_LENGHT (256)


/************** PROC ROOT DIRECTORY ***************/

#define PROCDIR "/proc"

enum
ProcEntryType {
    // For process info directories, like /proc/[pid]
    ProcessInfo,
    SystemInfo,
    SystemSettings,
    DevicesInfo,
    NetInfo,
    VirtualFileSystemsInfo,
    Undefined,
};

/*static const struct ProcEntry entry_name_to_type[] = {
    {.name = "cpuinfo",         .type = SystemInfo},
    {.name = "meminfo",         .type = SystemInfo},
    {.name = "version",         .type = SystemInfo},
    {.name = "uptime",          .type = SystemInfo},
    {.name = "filesystems",     .type = SystemInfo},
    {.name = "stat",            .type = SystemInfo},
    {.name = "swaps",           .type = SystemInfo},
    {.name = "partitions",      .type = SystemInfo},
    {.name = "diskstats",       .type = SystemInfo},
    {.name = "net",             .type = SystemInfo},
    {.name = "interrupts",      .type = SystemInfo},
    {.name = "iomem",           .type = SystemInfo},
    {.name = "ioports",         .type = SystemInfo},
    {.name = "cgroups",         .type = SystemInfo},
    {.name = "zoneinfo",        .type = SystemInfo},
    //TODO
};*/


/************** PROCESS INFO DIRECTORY ***************/

#define PROCINFO_DIR_DEPTH (2)

i32
is_process_id(const char *name);

char *
get_full_path(i32 item);

struct
Stat {
    i32     pid;
    u8      comm[MAX_FILE_NAME_LENGHT];
    u8      state;
    i32     ppid;
    i32     pgrp;
    i32     session;
    i32     tty_nr;
    i32     tpgid;
    u32     flags;
    u32     minflt;
    u32     cminflt;
    u32     majflt;
    u32     cmajflt;
    u32     utime;
    u32     stime;
    u32     cutime;
    u32     cstime;
    i32     priority;
    i32     nice;
    i32     num_threads;
    i32     itrealvalue;
    u64     starttime;
    u32     vsize;
    i32     rss;
    u32     rsslim;
    u32     startcode;
    u32     endcode;
    u32     startstack;
    u32     kstkesp;
    u32     kstkeip;
    u32     signal;
    u32     blocked;
    u32     sigignore;
    u32     sigcatch;
    u32     wchan;
    u32     nswap;
    u32     cnswap;
    i32     exit_signal;
    i32     processor;
    u32     rt_priority;
    u32     policy;
    u64     delayacct_blkio_ticks;
    u32     guest_time;
    i32     cguest_time;
    u32     start_data;
    u32     end_data;
    u32     start_brk;
    u32     arg_start;
    u32     arg_end;
    u32     env_start;
    u32     env_end;
    i32     exit_code;
};

struct
Statm {
    u64     size;
    u64     resident;
    u64     shared;
    u64     text;
    u64     lib;
    u64     data;
    u64     dt;
};

struct
Status {

};

static const char * to_long_record[] = {
    ['R'] = "Running",
    ['D'] = "Uninterruptible Sleep",
    ['S'] = "Interruptable Sleep",
    ['T'] = "Stopped",
    ['Z'] = "Zombie",
    ['X'] = "Dead",
    ['t'] = "Tracing stop",
};


/************** PROC ENTRY LIST ****************/

struct
ProcEntry {
    char                name[MAX_FILE_NAME_LENGHT];
    enum ProcEntryType  type;
    struct ProcEntry    *next;
    struct ProcEntry    *prev;
};

struct
ProcEntryList {
    struct ProcEntry    *head;
    struct ProcEntry    *tail;
};

// Create new instance ProcEntryList
struct ProcEntryList *
proc_entry_list_init(void);

struct ProcEntry *
proc_entry_init(void);

struct ProcEntry *
proc_entry_push(struct ProcEntry *entry, struct ProcEntryList *list);

#define proc_entry_list_foreach(entry, entry_list) \
for (entry = entry_list->head;                     \
     entry != entry_list->tail;                    \
     entry = entry->next)

static i32
proc_entry_pop(struct ProcEntryList *list);

i32
proc_entry_list_free(struct ProcEntryList *list);

struct ProcEntryList *
filter_entry_list(struct ProcEntryList *list, enum ProcEntryType filter);

#endif /* process.h */
