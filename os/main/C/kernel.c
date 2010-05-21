#include <main.h>
#include <stub.h>

void kmain( void* mbd, u32int magic )
{
    
    if ( magic != 0x2BADB002 )
    {
        kprint("Error booting the kernel", COMPOSE(BB, FL));
    }
    
    startup(mbd);
    //provoke_interrupt1();
}
