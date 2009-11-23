#include "kstr.h"

u32int kstrlen(const char *str)
{
    u32int count = 0;
    while(str[count] != '\0')
    {
        count++;
    }
    return count - 1; /*remove null character from the count*/
}
