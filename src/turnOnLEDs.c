/*******************************************************************
* File: turnOnLEDs.c
*  
* Author: Miles Osborne 
*
* Purpose: Application source for turning on both onboard LEDs of the 
* nRF7002DK development board
***********************************************************************/
#include "nrfx.h"
#include "nrf_gpio.h"

/*******************************************************************
*  Function: main
*
*  Purpose: Application entry point 
*********************************************************************/

int main(void) {
    /*******************************************************
    * Set P1.06 (LED1) to output and write a logical 1 to 
    * the pin to turn on the LED
    ********************************************************/ 
    NRF_P1->PIN_CNF[6] |= 1;
    NRF_P1->PIN_CNF[6] |= 1<<1;
    NRF_P1->DIR |= GPIO_DIR_PIN6_Output<<GPIO_DIR_PIN6_Pos;
    NRF_P1->OUTSET |= 1 << GPIO_OUTSET_PIN6_Pos;

    /*******************************************************
    * Set P1.07 (LED2) to output and write a logical 1 to 
    * the pin to turn on the LED
    ********************************************************/ 
    NRF_P1->PIN_CNF[7] |= 1;
    NRF_P1->PIN_CNF[7] |= 1<<1;
    NRF_P1->DIR |= GPIO_DIR_PIN7_Output<<GPIO_DIR_PIN7_Pos;
    NRF_P1->OUTSET |= 1 << GPIO_OUTSET_PIN7_Pos;
    
    while(1);

    return 0;
}
