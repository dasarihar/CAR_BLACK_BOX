/*
 * File:   digital_keypad.c
 * Author: kesar
 *
 * Created on 16 November, 2024, 11:30 PM
 */


#include <xc.h>

#include"black_box.h"

unsigned char read_matrix_keypad(unsigned char detection_type)
{
	static unsigned char once = 1;
    unsigned char key = scan_key();
    
    /*STATE CHANGE = edge triggering (CHANGE ONCE) */ 
    
	if (detection_type == 1)
	{
		if ((key != 0xff) && once)
		{
			once = 0;

			return key;
		}
		else if ((key) == 0xff)
		{
			once = 1;
		}
	}
	else if (detection_type == 0)
	{
		return key;
	}

	return 0xFF;
}
