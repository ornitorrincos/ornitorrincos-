#include <isr.h>
#include <vga.h>
#include <colors.h>

void isr_handler(struct registers reg)
{
    unhandled_exception(reg);
}

void unhandled_exception(struct registers reg)
{
    clear_screen();
    kprint("Interrupt code: ", COMPOSE(BU, LFL));
    kpint(reg.int_no, COMPOSE(BU, LFL));
    kprint("\n", COMPOSE(BB, FL));
}
