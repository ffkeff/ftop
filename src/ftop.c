/*
 *  \File: ftop.c
 *
 *  \Owner: ffkeff
 *
 *  \Created at 09-08-2024
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

#include "../include/procdriver.h"
#include "../include/process.h"

/************** TERMINAL SETTINGS ***************/

static struct termios old_settings;

void
set_new_settings(void) {
    struct termios  new_settings;

    //save old settings
    tcgetattr(fileno(stdin), &old_settings);

    new_settings = old_settings;
    new_settings.c_lflag &= ~(ECHO | ICANON | ISIG);
    new_settings.c_cc[VMIN] = 1;
    new_settings.c_cc[VTIME] = 1;
    tcsetattr(fileno(stdin), TCSANOW, &new_settings);
}

void
set_old_settings(void) {
    tcsetattr(fileno(stdin), TCSANOW, &old_settings);
}


/************** ENTRY POINT OF PROGRAM ***************/

int
main(void) {
    struct ProcEntryList    *entry_list;
    struct ProcEntry        *entry;

    entry_list = get_proc_entries();

    proc_entry_list_foreach(entry, entry_list) {
        printf("%s %d\n", entry->name, entry->type);
    }

    (void) exit (EXIT_SUCCESS);
}
