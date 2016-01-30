/* rot_video.h - holds definitions for video services */

#ifndef uint8_t
#include <stdint.h>
#endif

#ifndef bool
#include <stdbool.h>
#endif

#define BDAVIDSTAT (uint16_t*)0x410
#define MONOTERM 0x30
#define COLRTERM 0x20

#define MONOTERMADDR (uint8_t*)0xB0000
#define COLRTERMADDR (uint8_t*)0xB8000

#define TERMWIDTH 80
#define TERMHEIGHT 25
#define TERMDEPTH 2
#define TERMSIZE (TERMDEPTH * TERMHEIGHT * TERMWIDTH)
#define TERMCOLOUR 0x02

#define LINETERM 0
#define NEWLINE '\n'
#define BLANK ' '
