/*
 * File:   main.c
 * Author: derslik3-15
 *
 * Created on September 2, 2025, 11:26 AM
 */


#include <xc.h>
#include <stdint.h>

// Register File Map 

volatile uint8_t *pTRISB = (volatile uint8_t)0x86;  // Output / Input alan?
volatile uint8_t *pPORTB = (volatile uint8_t)0x06;  // Yakma ve söndürme sinyali
volatile uint8_t *pOPT?ONREG = (volatile uint8_t) 0x81; // option_reg_register
volatile uint8_t *pINTCONREG = (volatile uint8_t) 0x0B; // kesme registerlar? açma

// external interrupt  RB0 tek var
// interrupt vector 

void __interrupt(void){
    if(*pINTCONREG & (1<<0)){
        *pPORTB ^= (1<<2);
        
    }
}
void main(void) {
    *pTRISB |= (1u<<0); // input 
    *pTRISB &= ~(1u<<2); // output
    *pPORTB &= ~(1u<<2); // yanmas?n...
    
    *pOPT?ONREG &= ~(1u<<7); // pull up yap?ld?  
    *pINTCONREG |= (1u<<7);
    *pINTCONREG |= (1u<<4);
}



