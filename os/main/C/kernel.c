#include <main.h>
#include <stub.h>

void kmain( void* mbd, unsigned int magic )
{
    
    if ( magic != 0x2BADB002 )
    {
        kprint("Error booting the kernel", COMPOSE(BB, BL));
    }
    
    startup(mbd);
    //provoke_interrupt1();
}
