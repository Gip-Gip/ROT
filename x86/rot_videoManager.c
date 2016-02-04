/* rot_videoManager.c - detects and manages video */

#include <stdint.h>
#include <stdbool.h>
#include "rot_video.h"

#define LOGID "rot_videoControl(2.2016)"

#define MONOTERMFND "Monochrome terminal found!"
#define COLRTERMFND "Colour terminal found!"

extern void rot_terminalInit();
extern void rot_terminalPrint();
extern void rot_terminalClear();
extern void rot_log();

uint8_t *videoMemory = 0;
bool terminal = false;

void rot_videoInit( void )
{
    rot_terminalInit();
    if(videoMemory == MONOTERMADDR)
    {
        terminal = true;
        rot_terminalClear();
        rot_log(LOGID, MONOTERMFND);
    }

    else if(videoMemory == COLRTERMADDR)
    {
        terminal = true;
        rot_terminalClear();
        rot_log(LOGID, COLRTERMFND);
    }
}

void rot_print(char *_str_)
{
    if(terminal == true) rot_terminalPrint(_str_);
}
