#include <xc.h>
#include <stdio.h>
#include <stdlib.h>

void init_PWM(void){
//ROUE DROITE
    //initialisation du timer
    T2CONbits.TCKPS=0b01; //prescaler mis à 8
    PR2=25000; //pour avoir + que 3 ms de période car période=PRy/FCy et FCy=40 MHz
    T2CONbits.TCS = 0;
    
    //initialisation du PWM
    OC1CONbits.OCM=0b110; //on active le PWM
    OC1CONbits.OCTSEL=0; //correspond au timer2
    OC1R=5000;  //cf. page 30 où rapport cyclique delta=OC1R/(PR2+1) et ici on veut delta=20%
    OC1RS=5000;
    
    //lien entre le Output-Compare et le pin
    AD1PCFGL = 0x01FF; //met tous les pins en digital pour que la 2e roue tourne

    RPOR6bits.RP13R = 0b10010;
    RPOR6bits.RP12R = 0b10011;
    
    
//ROUE GAUCHE
    //initialisation du timer
    T3CONbits.TCKPS=0b01;
    PR3=25000; //pour avoir + que 3 ms de période car période=PRy/FCy et FCy=40 MHz
    T3CONbits.TCS = 0;
    
    //initialisation du PWM
    OC3CONbits.OCM=0b110; //on active le PWM
    OC3CONbits.OCTSEL=0; //correspond au timer2
    OC3R=10000;  //cf. page 30 où rapport cyclique delta=OC1R/(PR2+1) et ici on veut delta=40%
    OC3RS=10000;
    
//    RPOR9bits.RP18R = 0b10010;
//    RPOR6bits.RP12R = 0b10011;
 
    RPOR9bits.RP18R = 0b10100;
    RPOR6bits.RP12R = 0b10101;
}