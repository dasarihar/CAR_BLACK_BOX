/*
 * File:   internal_eeprom.c
 * Author: kesar
 *
 * Created on 20 November, 2024, 4:37 PM
 */


#include <xc.h>
#include "black_box.h"
#include "clcd1.h"

#include"EEprom.h"
#include"I2C.h"
#include"rtc.h"

void write_external_eeprom(unsigned char address, unsigned char data)
{
	i2c_start();
	i2c_write(SLAVE_WRITE_E);
	i2c_write(address);
	i2c_write(data);
	i2c_stop();
    for(int i=3000;i--;);
}

unsigned char read_external_eeprom(unsigned char address)
{
	unsigned char data;

	i2c_start();
	i2c_write(SLAVE_WRITE_E);
	i2c_write(address);
	i2c_rep_start();
	i2c_write(SLAVE_READ_E);
	data = i2c_read();
	i2c_stop();

	return data;
}

        