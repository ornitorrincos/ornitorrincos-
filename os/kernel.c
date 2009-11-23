#include "kio.h"
#include "vga.h"

void kmain( void* mbd, unsigned int magic )
{
    /*specify intel syntax for asm*/
    asm(".intel_syntax noprefix\n");
    
    if ( magic != 0x2BADB002 )
    {
        kprint("Error booting the kernel");
    }
  
    /* You could either use multiboot.h */
    /* (http://www.gnu.org/software/grub/manual/multiboot/multiboot.html#multiboot_002eh) */
    /* or do your offsets yourself. The following is merely an example. */ 
    char * boot_loader_name =(char*) ((long*)mbd)[16];
    
    /* Kernel starts here */
    /*kprint(boot_loader_name);*/
    mv_cursor(2, 0);
    kprint("hello");
}
