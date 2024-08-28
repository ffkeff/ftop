#include <stdio.h>

#include "../include/drawing.h"
#include "../include/ftop_types.h"

void
draw_frame(int width, int height) {
    printf("\033[35m");

    printf("┌%s", FRAME_HEADER);
    for (size_t i = FRAME_HEADER_LENGHT + 1; i < width - 1; ++i) {
        printf("\033[1;%zuH", i + 1);
        printf("─");
    }
    printf("┐");

    for (int i = 0; i < height - 2; ++i) {
        printf("│");
        for (int j = 0; j < width - 2; ++j) {
            printf(" ");
        }
        printf("│\n");
    }

    printf("└");
    for (int i = 1; i < width; ++i) {
        printf("─");
        printf("\033[%d;%dH", height, i + 1);
    }
    printf("┘");
}

void
print_proc_entry(struct ProcEntry *entry, int entry_index){
    int position;

    position = entry_index + 2;

    printf("\033[%d;2H", position);
    printf("%s | %d", entry->name, entry->type);
}

void
draw_process_bar(struct ProcEntryList *process_list, int width, int height){
    struct ProcEntry    *entry;
    int                 entry_index;
    int                 bar_capacity;

    if (!process_list) return;

    entry_index = 0;
    bar_capacity = height - 2;

    proc_entry_list_foreach(entry, process_list) {
        if (entry_index >= bar_capacity) break;

        print_proc_entry(entry, entry_index);

        ++entry_index;
    }
}

void
draw_cpu_bar(){}




