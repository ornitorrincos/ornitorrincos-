#ifndef CPUID_H
#define CPUID_H

void VendorString(char *str); /*gets the VendorString*/
void simd(int *ptr); /*gets mmx, sse, sse2, sse3, sse4*/
void amd_simd(int *ptr); /*gets 3dnow!, 3dnow!+*/
void pae(int *ptr); /*gets pae*/
void model(char *str);

#endif
