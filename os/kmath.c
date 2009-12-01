#include "kmath.h"

u32int power(u32int base, u32int exp)
{
    u32int aux;
    aux = base;
    if(exp == 1)
    {
        aux=base;
    }
    else if(exp == 0)
    {
        aux = 0;
    }
    else
    {
        while(exp > 1)
        {
            aux = aux*base;
            exp--;
        }
    }
    return aux;
}
