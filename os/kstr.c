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

u32int kdigit(u32int num)
{
    u32int aux;
    u32int count;
    /* We get the number's length */
    aux = num;
    while(aux>10)
    {
        aux = aux/10;
        count++;
    }
    return aux;
}

u32int kdigitlen(u32int num)
{
        u32int aux;
    u32int count;
    /* We get the number's length */
    aux = num;
    while(aux>10)
    {
        aux = aux/10;
        count++;
    }
    return count+1;
}
