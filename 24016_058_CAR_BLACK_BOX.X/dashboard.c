/*
 * File:   dashboard.c
 * Author: kesar
 *
 * Created on 13 December, 2024, 11:28 AM
 */


#include <xc.h>
#include "black_box.h"
#include "clcd1.h"

#include"EEprom.h"
#include"I2C.h"
#include"rtc.h"

unsigned int crush =0,add=0;
unsigned char key;
char str[10];

unsigned short speed_count=0;

void store_events(unsigned char time[],unsigned char gear[],int speed)
{
         str[0]=time[0];
         str[1]=time[1];
         str[2]=time[3];
         str[3]=time[4];
         str[4]=time[6];
         str[5]=time[7];
         str[6]=gear[0];
         str[7]=gear[1];
         str[8]=(speed/10+'0');
         str[9]=(speed%10+'0');
         str[10]='\0';
         store_count++;
      if (store_count >= 11) {
          write_addr = 0x00;
            for(int i=0;i<9;i++)
            {   
                for(int b=0;b<10;b++)
                {
                write_external_eeprom(write_addr++, read_external_eeprom((i+1)*10+b)); 
                }
        
            }  
             
       store_count=10;

    } 
        int i=0;
         while(str[i])
         {
             write_external_eeprom(write_addr++,str[i++]);
         }
    
}
  void view_dashboard()
  {
    
      init_adc();     
      
      if(key!=0xff)
      {
         if(key == 1)
          {
              index++;
              crush=0;
              store_events(time,gear[index],speed_count);
         
          }else if(key==2)
          {   
              index--;
              crush=0;
               store_events(time,gear[index],speed_count);
         
          }else if(key==3)
          {
              crush=1;
               store_events(time,gear[index],speed_count);
             
          }
          if(index<=0)
              index=1;
          if(index>=7)
              index=7;
          if(crush==0)
          {
          clcd_print(gear[index],LINE2(9));
          }
          else
          {
           clcd_print("C ",LINE2(9)); 
          }
      }
      get_time();
      clcd_print(time,LINE2(0)); 
      speed_count=read_adc();
      if(speed_count>=99)
          speed_count=99;
      if(speed_count<=0)
          speed_count=0;
      clcd_putch(speed_count%10+'0',LINE2(15));
      clcd_putch(speed_count/10+'0',LINE2(14));     
   
  }
