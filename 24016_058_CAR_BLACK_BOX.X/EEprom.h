/* 
 * File:   EEprom.h
 * Author: kesar
 *
 * Created on 20 December, 2024, 4:51 PM
 */

#ifndef EEPROM_H
#define	EEPROM_H



#define SLAVE_READ_E		0xA1
#define SLAVE_WRITE_E	0xA0




void write_external_eeprom(unsigned char address1,  unsigned char data);
unsigned char read_external_eeprom(unsigned char address);

#endif
/* EEPROM_H */

