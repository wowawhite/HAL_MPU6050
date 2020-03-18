/*
 * usb_print.h
 *
 *  Created on: Mar 18, 2020
 *      Author: wowa
 */

#ifndef INC_USB_PRINT_H_
#define INC_USB_PRINT_H_


void usb_transmit_byte(uint8_t transmit_int);
void usb_transmit_int(int32_t transmit_int);
void usb_transmit_uint(uint32_t transmit_uint);
void usb_transmit_float(float transmit_float);
void usb_transmit_char(char transmit_char);  // test this
void usb_transmit_string(char *transmit_string);  // test this


#endif /* INC_USB_PRINT_H_ */
