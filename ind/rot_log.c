/* rot_log.c - logs things */

extern void rot_print();

void rot_log(char *__id, char *__msg)
{
    rot_print(__id);
    rot_print(": ");
    rot_print(__msg);
    rot_print("\n");
}
