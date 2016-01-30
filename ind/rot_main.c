/* rot_main.c - calls a bunch of stuff */

#define LOGID "rot(1.2016)"
#define INITDONE "everything's done!"

extern void rot_videoInit();
extern void rot_log();

void rot_main( void )
{
    rot_videoInit();
    rot_log(LOGID, INITDONE);
}
