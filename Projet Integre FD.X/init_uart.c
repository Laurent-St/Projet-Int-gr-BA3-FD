#include <xc.h>
void init_uart(void){
    
    U1MODE = 0;
    
    U1MODEbits.BRGH = 0;
    //int FCY = 40*10^6;
    //int baudR = 115200;
    //U1BRG = FCY/(16 * baudR) - 1;
    U1BRG=20.7;
    U1MODEbits.UARTEN = 1;  //activer l'uart et la transmission
    U1STAbits.UTXEN = 1;
}