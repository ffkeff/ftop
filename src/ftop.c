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
#include <signal.h>
#include <sys/ioctl.h>

#include "../include/procdriver.h"
#include "../include/process.h"
#include "../include/drawing.h"

/************** TERMINAL SETTINGS ***************/

static struct termios old_settings;

void
set_raw_mode(void) {
    struct termios  new_settings;

    //save old settings
    (void) tcgetattr (fileno(stdin), &old_settings);

    new_settings = old_settings;
    new_settings.c_lflag &= ~(ECHO | ICANON | ISIG);
    new_settings.c_cc[VMIN] = 1;
    new_settings.c_cc[VTIME] = 1;
    (void) tcsetattr (fileno(stdin), TCSANOW, &new_settings);
}

void
set_old_mode(void) {
    (void) tcsetattr (fileno(stdin), TCSANOW, &old_settings);
}

void resize_handler(int sig) {
    struct winsize w;
    (void) ioctl (fileno(stdout), TIOCGWINSZ, &w);
    (void) draw_frame (w.ws_col, w.ws_row);
}

/************** ENTRY POINT OF PROGRAM ***************/

int
main(void) {
    struct winsize terminal_size;
    struct ProcEntryList    *entry_list;
    struct ProcEntryList    *process_list;

    (void) ioctl (fileno(stdout), TIOCGWINSZ, &terminal_size);

    (void) signal (SIGWINCH, resize_handler);

    system("clear");

    (void) set_raw_mode ();

    (void) draw_frame (terminal_size.ws_col, terminal_size.ws_row);

    entry_list = get_proc_entries();
    process_list = filter_entry_list(entry_list, ProcessInfo);
    (void) draw_process_bar (process_list, terminal_size.ws_col, terminal_size.ws_row);

    char c;
    while (1) {
        c = getchar();
        if (c == 'q') break;
        fflush(stdout);
    }

    (void) set_old_mode();

    system("clear");

    (void) exit (EXIT_SUCCESS);
}

/*  struct ProcEntryList    *entry_list;
    struct ProcEntry        *entry;

    entry_list = get_proc_entries();

    proc_entry_list_foreach(entry, entry_list) {
        printf("%s %d\n", entry->name, entry->type);
    }
*/

