#include <xc.h>

//  BITS DE CONFIGURATION
///////////////////////////////////////////////////////////////////////////////
// disables the JTAG to prevent conflicts with TRISA
_FICD(ICS_PGD1 & JTAGEN_OFF);

// disables the watchdog
_FWDT(FWDTEN_OFF);

// The dsPIC will be clocked by the primary oscillator with a 10MHz crystal.
// We want to use the PLL to obtain Fosc = 80MHz ( <=> 40MIPS ).
// Problem : with a 10MHz crystal, PLL constraints are not met with the
// default parameter.
// Solution :
//	- boot using the internal FRC oscillator as clock source,
//	- set the right PLL parameters to obtain Fosc = 80MHz, without violating
//	  the PLL constraints,
//	- switch the clock source to the PLL
//	- wait for the end of the clock switch
//
// Select internal FRC oscillator as clock source
_FOSCSEL(FNOSC_FRC);
// enables clock switching and configure the primary oscillator for a 10MHz crystal
_FOSC(FCKSM_CSECMD & OSCIOFNC_OFF & POSCMD_XT);


/*---------------------------------------------------------------------
  Function Name: Init_ADC
  Description:   Initialize ADC module
  Inputs:        None
  Returns:       None
-----------------------------------------------------------------------*/
void Init_ADC(void) {
    AD1CON1bits.AD12B = 1;
    AD1CON3bits.ADCS = 3;
    AD1PCFGL = 0; //toutes les pattes en analogique
    AD1CHS0bits.CH0SA = 0;  //met AN0 comme entree
    AD1CON1bits.ASAM = 1;  //échantillonnage automatique
    AD1CON1bits.SSRC = 0b010; //autoconvert? (choix du declenchement de la conversion)
    AD1CON1bits.ADON = 1; //activation de l'ADC ON/OFF
}
