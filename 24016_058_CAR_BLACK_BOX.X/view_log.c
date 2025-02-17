
/*
 * File:   view_log.c
 * Author: kesar
 *
 * Created on 18 December, 2024, 6:01 PM
 */


#include <xc.h>
#include "black_box.h"
#include "clcd1.h"

#include"EEprom.h"
#include"I2C.h"
#include"rtc.h"

unsigned int ind=0,view=0;
void view_log(void) {
    change_menu = 0;
     
    if(store_count == 0)                            //IF THERE IS NO EVENTS                           
    {
        clcd_print("NO LOGS         ",LINE1(0));
        clcd_print("ENTERED    ",LINE2(0));
        
        for(unsigned long int i=500000;i--;);
        CLEAR_DISP_SCREEN;
        
    }
    else                                      //IF THERE ARE EVENTS
    {
        if(view == 0)
        {
            clcd_print("#   TIME   EV SP", LINE1(0));
            view=1;
           int  add=0X00;
            for(int i=0;i<store_count;i++)
            {
                for(int j=0;j<17;j++)
                {
                    if(j==0)
                        str1[i][j]=i+'0';
                    else if(j==1 || j==10 || j==13)
                        str1[i][j]=' ';
                    else if(j==4 || j==7)
                        str1[i][j]=':';
                    else if(j==16)
                        str1[i][j]='\0';
                    else
                        str1[i][j]=read_external_eeprom(add++);
                }
            }
         }          
            
        clcd_print(str1[ind],LINE2(0));
        
         key = read_matrix_keypad(1);
        
        if(key == 2 && ind < (store_count-1))
            ind++;
        else if(key == 1 && ind > 0)
            ind--;
        
    }
}
