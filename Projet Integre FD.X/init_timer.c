#include <xc.h>

void init_timer(void){
    PR3 = (200*10^(-6)/(25*10^(-9)))-1;
    T3CONbits.TCS = 0;
}
