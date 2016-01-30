/* rot_terminal.c - provides terminal output */

#include <stdint.h>
#include <stdbool.h>
#include "rot_video.h"

extern uint8_t *videoMemory;
unsigned int cursor = 0;

void rot_terminalInit( void )
{
    if((*(BDAVIDSTAT) & MONOTERM) == MONOTERM)
        videoMemory = MONOTERMADDR;

    else if((*(BDAVIDSTAT) & COLRTERM) == COLRTERM)
        videoMemory = COLRTERMADDR;
}

void rot_terminalPrint(uint8_t *__str)
{
    while(*__str != LINETERM)
    {
        if(*__str == NEWLINE)
        {
            cursor = ((cursor / TERMWIDTH) + 1) * TERMWIDTH;
            __str ++;
        }

        else
        {
            *(videoMemory + cursor) = *__str;
            cursor += TERMDEPTH;
            __str ++;
        }
    }
}

void rot_terminalClear( void )
{
    cursor = 0;

    while(cursor < TERMSIZE)
    {
        *(videoMemory + cursor) = BLANK;

        if(videoMemory == COLRTERMADDR)
            *(videoMemory + cursor + 1) = TERMCOLOUR;

        cursor += TERMDEPTH;
    }

    cursor = 0;
}
