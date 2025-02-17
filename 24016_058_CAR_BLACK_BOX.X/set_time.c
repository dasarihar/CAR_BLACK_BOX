/*
 * File:   set_time.c
 * Author: kesar
 *
 * Created on 25 December, 2024, 11:12 AM
 */

#include<xc.h>
#include "black_box.h"
#include "clcd1.h"

#include"EEprom.h"
#include"I2C.h"
#include"rtc.h"
int blink = 1, hms = 0;

void set_time() {
    set_flag=1;
    CLEAR_DISP_SCREEN;
    change_menu = 0;
    if (once == 0) {
        once = 1;
        get_time();
        hour = (time[0] - '0')*10;
        hour = hour + (time[1] - '0');

        min = (time[3] - '0')*10;
        min = min + (time[4] - '0');

        sec = (time[6] - '0')*10;
        sec = sec + (time[7] - '0');
    }
    blink = !blink;
    if (key == 2) {
        if (hms >= 0 && hms < 2)
            hms++;
        else if (hms >= 2)
            hms = 0;
    }
    if (key == 1) {
        if (hms == 0) {
            if (hour >= 0 && hour < 23) {
                hour++;
            } else
                hour = 0;
        }
        if (hms == 1) {
            if (min >= 0 && min < 59) {
                min++;
            } else
                min = 0;
        }
        if (hms == 2) {
            if (sec >= 0 && sec < 59) {
                sec++;
            } else
                sec = 0;
        }
    }


    if (hms == 0) {
        if (blink) {
            clcd_putch((hour / 10 + '0'), LINE2(0));
            clcd_putch((hour % 10 + '0'), LINE2(1));
             clcd_putch(':', LINE2(2));
            
            clcd_putch((min / 10 + '0') , LINE2(3));
            clcd_putch((min % 10 + '0'), LINE2(4));
            clcd_putch(':', LINE2(5));
            clcd_putch((sec / 10 + '0'), LINE2(6));
            clcd_putch((sec % 10 + '0'), LINE2(7));
        } else {
            clcd_putch(' ', LINE2(0));
            clcd_putch(' ', LINE2(1));
            clcd_putch(':', LINE2(2));
            clcd_putch((min / 10 + '0'), LINE2(3));
            clcd_putch((min % 10 + '0'), LINE2(4));
            clcd_putch(':', LINE2(5));
            clcd_putch((sec / 10 + '0'), LINE2(6));
            clcd_putch((sec % 10 + '0'), LINE2(7));

        }
        for(long int i=100000;i--;);
       
    } else if (hms == 1) {

        if (blink) {
            clcd_putch((hour / 10 + '0'), LINE2(0));
            clcd_putch((hour % 10 + '0'), LINE2(1));
             clcd_putch(':', LINE2(2));
            
            clcd_putch((min / 10 + '0') , LINE2(3));
            clcd_putch((min % 10 + '0'), LINE2(4));
            clcd_putch(':', LINE2(5));
            clcd_putch((sec / 10 + '0'), LINE2(6));
            clcd_putch((sec % 10 + '0'), LINE2(7));
        } else {
            clcd_putch((hour / 10 + '0'), LINE2(0));
            clcd_putch((hour % 10 + '0'), LINE2(1));
            clcd_putch(':', LINE2(2));
            clcd_putch(' ', LINE2(3));
            clcd_putch(' ', LINE2(4));
            clcd_putch(':', LINE2(5));
            clcd_putch((sec / 10 + '0'), LINE2(6));
            clcd_putch((sec % 10 + '0'), LINE2(7));

        }
        for(long int i=100000;i--;);
      
    } else if (hms == 2) {
        if (blink) {
           clcd_putch((hour / 10 + '0'), LINE2(0));
            clcd_putch((hour % 10 + '0'), LINE2(1));
             clcd_putch(':', LINE2(2));
            
            clcd_putch((min / 10 + '0') , LINE2(3));
            clcd_putch((min % 10 + '0'), LINE2(4));
            clcd_putch(':', LINE2(5));
            clcd_putch((sec / 10 + '0'), LINE2(6));
            clcd_putch((sec % 10 + '0'), LINE2(7));
        } else {
            clcd_putch((hour / 10 + '0'), LINE2(0));
            clcd_putch((hour % 10 + '0'), LINE2(1));
            clcd_putch(':', LINE2(2));
            clcd_putch((min / 10 + '0') , LINE2(3));
            clcd_putch((min % 10 + '0'), LINE2(4));
            clcd_putch(':', LINE2(5));
            clcd_putch(' ', LINE2(6));
            clcd_putch(' ', LINE2(7));

        }
        for(long int i=100000;i--;);
       
    }
   
}
