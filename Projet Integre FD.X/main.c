/* 
 * File:   main.c
 * Author: Labo
 *
 * Created on 15 février 2017, 14:14
 */
#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include "init_uart.h"
#include "init.h"
#include "init_PWM.h"

//#define TEST_UART
#define PWM
/*
 * 
 */
#ifdef TEST_UART
int main(int argc, char** argv) {
    init();
    init_uart();
    init_ADC();
    while(1){
        RPINR18bits.U1RXR = 6;
        

        //U1TXREG = 00101;
        RPOR3bits.RP7R = 3;
    
        if (U1STAbits.URXDA == 1){
            U1RXREG;    //lire le registre
            T3CONbits.TON = 1; //demarrage timer
            //U1TXREG = U1RXREG; //On copie contenu registre RX dans TX
            for (int i=0;i<1000;i++){
                if (AD1CON1bits.DONE == 1){
                    AD1CON1bits.DONE = 0;
                    U1TXREG = ADC1BUF0 >> 4;    //décalage de 4 bits (/16)
                    
                }
            }
        } 
        


    }


//return (EXIT_SUCCESS);    
    return 0;
}
#endif

#ifdef PWM
int i;
int main(int argc, char** argv) {
    init();
    init_PWM();
    T2CONbits.TON = 1; //demarrage timer
    T3CONbits.TON = 1;
    while(1){
        //permet au programme de rester dans cette boucle sans rénéitialiser le timer
    }
    return 0;
}
#endif
