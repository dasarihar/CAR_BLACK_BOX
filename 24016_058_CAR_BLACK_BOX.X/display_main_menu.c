/*
 * File:   display_main_menu.c
 * Author: kesar
 *
 * Created on 14 December, 2024, 12:58 PM
 */


#include <xc.h>
#include "black_box.h"
#include "clcd1.h"
#include"EEprom.h"
#include"I2C.h"
#include"rtc.h"
int count1 = 0, count2 = 0, change_index = 0;

void display_main_menu() {

    if (key == 1) {

        if (count1 != 0)
        {
            main_index++;
            
        }
        change_index++;
        flag_menu = 1;
        count2 = 0;
        count1++;
        
        CLEAR_DISP_SCREEN;
    } else if (key == 2) {

        if (count2 != 0)
        {
            main_index--;
            
        }
        change_index--;
        flag_menu = 2;
        count2++;

        count1 = 0;
        
        CLEAR_DISP_SCREEN;
    }
    if (key==11&&change_menu>1)
    {
            CLEAR_DISP_SCREEN;
            if (change_index > 3)
                change_index = 3;
            if (change_index < 0)
                change_index = 0;        
    if(change_index==0)
    {
            CLEAR_DISP_SCREEN;
            state = e_view_log;  
    }
    if(change_index==2)
    {
        CLEAR_DISP_SCREEN;
        state=e_download_log;
    }
    if(change_index==1)
    {
        CLEAR_DISP_SCREEN;
         clcd_print("clearing .......",LINE1(0));
         for(int i=20000;i--;);
        state=e_clear_log;
    }
    if(change_index==3)
    {
        CLEAR_DISP_SCREEN;
         get_time();
         state=e_set_time;
         once=0;
    }
    }
    if (main_index < 0)
        main_index = 0;
    if (main_index > 2)
        main_index = 2;
   
    if (flag_menu == 1) {

        clcd_putch(' ', LINE1(0));
        clcd_print(main_menu[main_index], LINE1(3));
        clcd_print(main_menu[main_index + 1], LINE2(3));
        clcd_putch('*', LINE2(0));

    }
    if (flag_menu == 2) {

        clcd_putch(' ', LINE2(0));
        clcd_print(main_menu[main_index], LINE1(3));
        clcd_print(main_menu[main_index + 1], LINE2(3));
        clcd_putch('*', LINE1(0));
    }
}


