#include <xc.h>


void Init_ADC(void) {
    AD1CON1bits.AD12B = 1;
    AD1CON3bits.ADCS = 3;
    AD1PCFGL = 0; //toutes les pattes en analogique
    AD1CHS0bits.CH0SA = 0;  //met AN0 comme entree
    AD1CON1bits.ASAM = 1;  //échantillonnage automatique
    AD1CON1bits.SSRC = 0b010; //autoconvert? (choix du declenchement de la conversion)
    AD1CON1bits.ADON = 1; //activation de l'ADC ON/OFF
}
