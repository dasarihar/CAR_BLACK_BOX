/*
 * File:   init_timer.c
 * Author: kesar
 *
 * Created on 28 November, 2024, 3:42 PM
 */


#include <xc.h>
#include"header.h"
void init_timer0(void) {
    GIE = 1;
    PEIE = 1;
    TMR0IE = 1;
    TMR0IF = 0;
    TMR0ON = 1;
    T08BIT = 1;
    T0CS = 0;
    PSA = 1;
    TMR0 = 6;

}
