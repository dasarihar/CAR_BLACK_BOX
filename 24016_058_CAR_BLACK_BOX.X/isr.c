/*
 * File:   ISR.c
 * Author: kesar
 *
 * Created on 28 November, 2024, 3:51 PM
 */


#include <xc.h>
#include"header.h"

void __interrupt() isr() {
    static unsigned int count = 0;
    if (TMR0IF) {
        TMR0 = TMR0 + 8;

        if (++count == 20000) {
            sec_count++;

            count = 0;
        }
        TMR0IF = 0;
    }

}

