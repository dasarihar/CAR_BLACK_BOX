/*
 * File:   clear_log.c
 * Author: kesar
 *
 * Created on 24 December, 2024, 5:49 PM
 */


#include <xc.h>
#include "black_box.h"
#include "clcd1.h"

#include"EEprom.h"
#include"I2C.h"
#include"rtc.h"

 void clear_log()
 {
       change_menu = 0;
       store_count=0;
       
       clcd_print("ALL LOGS CLEARED",LINE1(0));
        for(int i=20000;i--;);
    
     
 }
