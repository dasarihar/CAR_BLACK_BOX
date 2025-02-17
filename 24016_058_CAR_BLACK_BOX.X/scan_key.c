/*
 * File:   scan_key.c
 * Author: kesar
 *
 * Created on 3 December, 2024, 4:59 PM
 */


#include <xc.h>

unsigned char scan_key(void) {
    RB5=0;
    RB6=RB7=1;
    if(RB1==0)
        return 1;
    else if(RB2==0)
        return 4;
    else if(RB3==0)
        return 7;
    else if(RB4==0)
        return 10;
    RB6=0;
    RB5=RB7=1;
    if(RB1==0)
        return 2;
    else if(RB2==0)
        return 5;
    else if(RB3==0)
        return 8;
    else if(RB4==0)
        return 11;
    RB7=0;
    RB6=RB5=1;
    if(RB1==0)
        return 3;
    else if(RB2==0)
        return 6;
    else if(RB3==0)
        return 9;
    else if(RB4==0)
        return 12;
    return 0xff;
}
