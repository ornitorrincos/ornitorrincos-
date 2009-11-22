#include <stdio.h>
#include <stdlib.h>
#include "cpuid.h"

int main(void)
{
    /*int i;*/
    char *sty;
    char str[13];
    int _features[5] = {0,0,0,0,0};
    
/*    for(i=0;i<5;i++)
    {
        _features[i] = 0;
    }*/
    
    VendorString(str);
    simd(_features);
    printf("%s\n", str);
    printf("MMX: %i\nSSE: %i\nSSE2: %i\nSSE3: %i\nSSE4: %i\n", _features[0], _features[1], _features[2], _features[3], _features[4]);
    _features[0] = 0;
    _features[1] = 0;
    _features[2] = 0;
    amd_simd(_features);
    printf("AMD extensions\n");
    printf("3DNow!: %i\n3DNow!+: %i\nMMX Ext: %i\n", _features[0], _features[1], _features[2]);
    _features[0] = 0;
    pae(_features);
    printf("--- Others ---\n");
    printf("pae: %i\n", _features[0]);
    sty = (char*) malloc(48*sizeof(char));
    model(sty);
    printf("CPU model\n");
    printf("%s\n", sty);
    free(sty);
    return 0;
}
