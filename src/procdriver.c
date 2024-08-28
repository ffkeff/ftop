/*
 *  \File: procdriver.c
 *
 *  \Owner: ffkeff
 *
 *  \Created at 09-08-2024
 *
 */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#include "../include/procdriver.h"

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

char *
read_from(i32 process_id) {
    char        *path;
    struct stat st;
    int         fd;
    char        *data;

    path = get_full_path(process_id);

    fd = open(path, O_RDONLY, S_IRUSR);

    fstat(fd, &st);

    data = (char*)malloc(st.st_size);

    read(fd, data, st.st_size);

    return data;
}

struct Stat *
get_stat_attributes(char *stat) {
    struct Stat   *attributes;

    attributes = (struct Stat*)malloc(sizeof (struct Stat));

    sscanf(stat,
           "%d %s %c %d %d %d %d %d %u %lu %lu %lu %lu %lu %lu %ld %ld %ld %ld %ld"
           "%ld %llu %lu %ld %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu %d"
           "%d %u %u %llu %lu %ld %lu %lu %lu %lu %lu %lu %lu %d",
           &attributes->pid, attributes->comm, &attributes->state, &attributes->ppid, &attributes->pgrp,
           &attributes->session, &attributes->tty_nr, &attributes->tpgid, &attributes->flags, &attributes->minflt,
           &attributes->cminflt, &attributes->majflt, &attributes->cmajflt, &attributes->utime, &attributes->stime,
           &attributes->cutime, &attributes->cstime, &attributes->priority, &attributes->nice, &attributes->num_threads,
           &attributes->itrealvalue, &attributes->starttime, &attributes->vsize, &attributes->rss, &attributes->rsslim,
           &attributes->startcode, &attributes->endcode, &attributes->startstack, &attributes->kstkesp, &attributes->kstkeip,
           &attributes->signal, &attributes->blocked, &attributes->sigignore, &attributes->sigcatch, &attributes->wchan,
           &attributes->nswap, &attributes->cnswap, &attributes->exit_signal, &attributes->processor, &attributes->rt_priority,
           &attributes->policy, &attributes->delayacct_blkio_ticks, &attributes->guest_time, &attributes->cguest_time, &attributes->start_data,
           &attributes->end_data, &attributes->start_brk, &attributes->arg_start, &attributes->arg_end, &attributes->env_start,
           &attributes->env_end, &attributes->exit_code);

    return attributes;
}

void *
get_stat_attribute(i32 desc, i32 attribute) {

}

struct Statm *
get_statm_attributes(FILE *statm) {

}

void *
get_statm_attribute(i32 desc, i32 attribute) {

}

struct Status *
get_status_attributes(i32 process_id) {

}
