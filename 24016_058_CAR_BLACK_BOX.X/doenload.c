/*
 * File:   doenload.c
 * Author: kesar
 *
 * Created on 27 December, 2024, 5:42 PM
 */


#include <xc.h>
#include "black_box.h"
#include "clcd1.h"

#include"EEprom.h"
#include"I2C.h"
#include"rtc.h"
#include "uart.h"

 void download_log()
 {
     CLEAR_DISP_SCREEN;
     clcd_print("Entered into uart",LINE1(0));

     for(int i=0;i<store_count;i++)
     {
           puts(str1[i]);
           puts("\n\r");
     }
     state = e_main_menu;
 }
