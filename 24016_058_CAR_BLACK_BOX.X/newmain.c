
/*
 * File:   main.c
 * Author: kesar
 *
 * Created on 14 February, 2024, 5:40 PM
 */

#include <xc.h>
#include "black_box.h"
#include "clcd1.h"

#include"EEprom.h"
#include"I2C.h"
#include"rtc.h"
#include "uart.h"




 void init_ds1307();

void display_time(void)
{
	    
    clcd_print(time, LINE2(0));

}
void get_time(void)
{
	clock_reg[0] = read_ds1307(HOUR_ADDR);
	clock_reg[1] = read_ds1307(MIN_ADDR);
	clock_reg[2] = read_ds1307(SEC_ADDR);

	if (clock_reg[0] & 0x40)
	{
		time[0] = '0' + ((clock_reg[0] >> 4) & 0x01);
		time[1] = '0' + (clock_reg[0] & 0x0F);
	}
	else
	{
		time[0] = '0' + ((clock_reg[0] >> 4) & 0x03);
		time[1] = '0' + (clock_reg[0] & 0x0F);
	}
	time[2] = ':';
	time[3] = '0' + ((clock_reg[1] >> 4) & 0x0F);
	time[4] = '0' + (clock_reg[1] & 0x0F);
	time[5] = ':';
	time[6] = '0' + ((clock_reg[2] >> 4) & 0x0F);
	time[7] = '0' + (clock_reg[2] & 0x0F);
	time[8] = '\0';
}


unsigned short speed_count = 0;

static void init_config1(void) {
    init_clcd();

}

void init_config() {

    state = e_dashboard;
}

void init_config2(void) {
    init_clcd();
    TRISB = 0x1E;
    RBPU = 0;

}

void main(void) {
    init_config1();
    init_config();
    init_uart();
    init_i2c();
   
    init_ds1307();
   
    init_config2();

    clcd_print("TIME", LINE1(0));
    clcd_print("GR", LINE1(9));
    clcd_print("SP", LINE1(14));
    clcd_print("ON", LINE2(9));
    while (1) {
        // Detect key press
        key = read_matrix_keypad(1);
        if (key == 11) {
            change_menu++;
            CLEAR_DISP_SCREEN;
            state = e_main_menu;
            clcd_putch('*', LINE1(0));
            clcd_print(main_menu[0], LINE1(3));
            clcd_print(main_menu[1], LINE2(3));

        }
      
        if (key == 12) {
            CLEAR_DISP_SCREEN;
            clcd_print("TIME", LINE1(0));
            clcd_print("GR", LINE1(9));
            clcd_print("SP", LINE1(14));
            clcd_print("ON", LINE2(9));
            state = e_dashboard;   
            if(set_flag==1)
            {
                set_flag=0;
         write_ds1307(HOUR_ADDR, (((hour / 10 ) << 4) | (hour % 10 )));
        write_ds1307(MIN_ADDR, (((min / 10 ) << 4) | (min % 10 )));
        write_ds1307(SEC_ADDR, (((sec / 10 ) << 4) | (sec % 10 )));
            }
        }
         
        switch (state) {
            case e_dashboard:
                // Display dashboard
                view_dashboard();
                break;

            case e_main_menu:
                // Display dashboard
                display_main_menu();
                break;

                  case e_view_log:
                      // Display dashboard
                      view_log();
                      break;
                 
                  case e_download_log:
                      download_log();
                      break;
                
                  case e_clear_log:
                      CLEAR_DISP_SCREEN;
                      clear_log();
                      break;
                
                      
                  case e_set_time:
                      set_time();
                      break;

        }

    }

}
