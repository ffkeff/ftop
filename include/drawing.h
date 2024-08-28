#ifndef DRAWING_H
#define DRAWING_H

#include <string.h>

#include "../include/process.h"

#define FRAME_HEADER "[PERFOMANCE | PROCESSES | ADDITIONAL]"
#define FRAME_HEADER_LENGHT strlen(FRAME_HEADER)

void
draw_frame(int width, int height);

void
draw_process_bar(struct ProcEntryList *process_list, int width, int height);

#endif/* drawing.h */
