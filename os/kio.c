#include "kio.h"

void kprint(const char *str)
{
    int i = 0;
    unsigned char *videoram = (unsigned char*) 0xB8000;
    /*videoram starts on first character byte*/
    while(str[i] != '\0')
    {
        *videoram=str[i]; /*copy the letter to the videoram position*/
        videoram++; /*move pointer to color byte*/
        *videoram = 0x07; /*foreground and background colors*/
        videoram++; /*move pointer to next character byte*/
        i++; /*next character on string*/
    }
}
