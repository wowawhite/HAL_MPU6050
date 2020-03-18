/*
 * usb_print.c
 *
 *  Created on: Mar 18, 2020
 *      Author: wowa
 */

#include "usb_device.h"
#include "usb_print.h"

extern USBD_HandleTypeDef hUsbDeviceFS;


void usb_transmit_byte(uint8_t transmit_byte)
{
	CDC_Transmit_FS(transmit_byte, 1);
}
void usb_transmit_int(int32_t transmit_int)  // ok but sprintf is dangerous
{
	uint8_t stringbuf[10];
	sprintf(stringbuf,  "%d", transmit_int);
	CDC_Transmit_FS(stringbuf, strlen(stringbuf));
}
void usb_transmit_uint(uint32_t transmit_uint)  // ok but sprintf is dangerous
{
	uint8_t stringbuf[10];
	sprintf(stringbuf,  "%u", transmit_uint);
	CDC_Transmit_FS(stringbuf, strlen(stringbuf));
}
void usb_transmit_char(char transmit_char)
{
	CDC_Transmit_FS(transmit_char, 1);
}
void usb_transmit_string( char *transmit_string)
{
	CDC_Transmit_FS(  transmit_string, strlen(transmit_string));
}
void usb_transmit_float(float transmit_float)
{
	char fullstring[20];
	char *tmpSign = (transmit_float < 0) ? "-" : " ";
	float tmpVal = (transmit_float < 0) ? -transmit_float : transmit_float;
	int tmpInt1 = tmpVal;                  // Get the integer (9876543210).
	float tmpFrac = tmpVal - tmpInt1;      // Get fraction (0.012).
	int tmpInt2 = (tmpFrac * 100);  // Turn into integer (12).
	sprintf (fullstring, "%s%d.%2d", tmpSign, tmpInt1, tmpInt2);

	CDC_Transmit_FS( (uint8_t*) fullstring, strlen(fullstring));
}
