/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*-
 *
 * Copyright (C) 2011-2015 Richard Hughes <richard@hughsie.com>
 *
 * Licensed under the GNU General Public License Version 2
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#if !defined (__COLORHUG_H_INSIDE__) && !defined (CD_COMPILATION)
#error "Only <colorhug.h> can be included directly."
#endif

#ifndef CH_COMMON_H
#define CH_COMMON_H

#include <glib.h>
#include <gusb.h>

G_BEGIN_DECLS

/* device constants */
#define	CH_USB_VID				0x273f
#define	CH_USB_PID_BOOTLOADER			0x1000
#define	CH_USB_PID_BOOTLOADER_DFU		0x100a
#define	CH_USB_PID_BOOTLOADER2			0x1005
#define	CH_USB_PID_BOOTLOADER_ALS		0x1006	/* since 1.2.9 */
#define	CH_USB_PID_BOOTLOADER_PLUS		0x1003
#define	CH_USB_PID_FIRMWARE			0x1001
#define	CH_USB_PID_FIRMWARE_DFU			0x1009
#define	CH_USB_PID_FIRMWARE2			0x1004
#define	CH_USB_PID_FIRMWARE_ALS			0x1007	/* since 1.2.9 */
#define	CH_USB_PID_FIRMWARE_ALS_SENSOR_HID	0x1008	/* since 1.2.11 */
#define	CH_USB_PID_FIRMWARE_PLUS		0x1002
#define	CH_USB_CONFIG				0x0001
#define	CH_USB_INTERFACE			0x0000
#define	CH_USB_HID_EP				0x01
#define	CH_USB_HID_EP_IN			(CH_USB_HID_EP | 0x80)
#define	CH_USB_HID_EP_OUT			(CH_USB_HID_EP | 0x00)
#define	CH_USB_HID_EP_SIZE			64

/* old device constants */
#define	CH_USB_VID_LEGACY			0x04d8
#define	CH_USB_PID_LEGACY			0xf8da

/* the default timeout in client tools */
#define CH_DEVICE_USB_TIMEOUT			10000 /* ms */

/* constants for ownership tags */
#define CH_OWNER_LENGTH_MAX			60

/**
 * CH_CMD_GET_COLOR_SELECT:
 *
 * Get the color select state.
 *
 * IN:  [1:cmd]
 * OUT: [1:retval][1:cmd][1:color_select]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ??       |      ???
 * ColorHug2      |      ??       |      ??
 * ColorHug+      |      ??       |      ??
 * ColorHugALS    |      ??       |      ???
 *
 * Since: 0.1.29
 **/
#define	CH_CMD_GET_COLOR_SELECT			0x01

/**
 * CH_CMD_SET_COLOR_SELECT:
 *
 * Set the color select state.
 *
 * IN:  [1:cmd][1:color_select]
 * OUT: [1:retval][1:cmd]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ??       |      ???
 * ColorHug2      |      ??       |      ??
 * ColorHug+      |      ??       |      ??
 * ColorHugALS    |      ??       |      ???
 *
 * Since: 0.1.29
 **/
#define	CH_CMD_SET_COLOR_SELECT			0x02

/**
 * CH_CMD_GET_MULTIPLIER:
 *
 * Gets the multiplier value.
 *
 * IN:  [1:cmd]
 * OUT: [1:retval][1:cmd][1:multiplier_value]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ??       |      ???
 * ColorHug2      |      ??       |      ??
 * ColorHug+      |      ??       |      ??
 * ColorHugALS    |      ??       |      ???
 *
 * Since: 0.1.29
 **/
#define	CH_CMD_GET_MULTIPLIER			0x03

/**
 * CH_CMD_SET_MULTIPLIER:
 *
 * Sets the multiplier value.
 *
 * IN:  [1:cmd][1:multiplier_value]
 * OUT: [1:retval][1:cmd]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ??       |      ???
 * ColorHug2      |      ??       |      ??
 * ColorHug+      |      ??       |      ??
 * ColorHugALS    |      ??       |      ???
 *
 * Since: 0.1.29
 **/
#define	CH_CMD_SET_MULTIPLIER			0x04

/**
 * CH_CMD_GET_INTEGRAL_TIME:
 *
 * Gets the integral time.
 *
 * IN:  [1:cmd]
 * OUT: [1:retval][1:cmd][2:integral_time]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ??       |      ???
 * ColorHug2      |      ??       |      ??
 * ColorHug+      |      ??       |      ???
 * ColorHugALS    |      ??       |      ???
 *
 * Since: 0.1.29
 **/
#define	CH_CMD_GET_INTEGRAL_TIME		0x05

/**
 * CH_CMD_SET_INTEGRAL_TIME:
 *
 * Sets the integral time.
 *
 * IN:  [1:cmd][2:integral_time]
 * OUT: [1:retval][1:cmd]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ??       |      ???
 * ColorHug2      |      ??       |      ??
 * ColorHug+      |      ??       |      ???
 * ColorHugALS    |      ??       |      ???
 *
 * Since: 0.1.29
 **/
#define	CH_CMD_SET_INTEGRAL_TIME		0x06

/**
 * CH_CMD_GET_FIRMWARE_VERSION:
 *
 * Gets the firmware version.
 *
 * IN:  [1:cmd]
 * OUT: [1:retval][1:cmd][2:major][2:minor][2:micro]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ???       |      ???
 * ColorHug2      |      ???       |      ???
 * ColorHug+      |      ???       |      ???
 * ColorHugALS    |      ???       |      ???
 *
 * Since: 0.1.29
 **/
#define	CH_CMD_GET_FIRMWARE_VERSION		0x07

/**
 * CH_CMD_GET_CALIBRATION:
 *
 * Gets the calibration matrix. The description does not have to be NULL
 * terminated.
 *
 * @types is a bitmask which corresponds to:
 *
 * bit:
 *  0     Can be used with LCD panels
 *  1     Can be used with CRT monitors
 *  2     Can be used with projectors
 *  3     Can be used with LED panels
 *  4-7   Reserved for future use
 *
 * IN:  [1:cmd][2:index]
 * OUT: [1:retval][1:cmd][2*9:matrix_value][1:types][23:description]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ??       |      ???
 * ColorHug2      |      ??       |      ???
 * ColorHug+      |      ??       |      ??
 * ColorHugALS    |      ??       |      ??
 *
 * Since: 0.1.29
 **/
#define	CH_CMD_GET_CALIBRATION			0x09

/**
 * CH_CMD_SET_CALIBRATION:
 *
 * Sets the calibration matrix.
 *
 * IN:  [1:cmd][2:index][4*9:matrix_value][1:types][23:description]
 * OUT: [1:retval][1:cmd]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ??       |      ???
 * ColorHug2      |      ??       |      ???
 * ColorHug+      |      ??       |      ??
 * ColorHugALS    |      ??       |      ??
 *
 * Since: 0.1.29
 **/
#define	CH_CMD_SET_CALIBRATION			0x0a

/**
 * CH_CMD_GET_SERIAL_NUMBER:
 *
 * Gets the device serial number.
 *
 * IN:  [1:cmd]
 * OUT: [1:retval][1:cmd][4:serial_number]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ??       |      ???
 * ColorHug2      |      ??       |      ???
 * ColorHug+      |      ??       |      ???
 * ColorHugALS    |      ??       |      ???
 *
 * Since: 0.1.29
 **/
#define	CH_CMD_GET_SERIAL_NUMBER		0x0b

/**
 * CH_CMD_SET_SERIAL_NUMBER:
 *
 * Sets the device serial number.
 *
 * IN:  [1:cmd][4:serial_number]
 * OUT: [1:retval][1:cmd]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ??       |      ???
 * ColorHug2      |      ??       |      ???
 * ColorHug+      |      ??       |      ???
 * ColorHugALS    |      ??       |      ??
 *
 * Since: 0.1.29
 **/
#define	CH_CMD_SET_SERIAL_NUMBER		0x0c

/**
 * CH_CMD_GET_LEDS:
 *
 * Get the LED state.
 *
 * IN:  [1:cmd]
 * OUT: [1:retval][1:cmd][1:led_state]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ??       |      ???
 * ColorHug2      |      ??       |      ???
 * ColorHug+      |      ??       |      ???
 * ColorHugALS    |      ???       |      ???
 *
 * Since: 0.1.29
 **/
#define	CH_CMD_GET_LEDS				0x0d

/**
 * CH_CMD_SET_LEDS:
 *
 * Set the LED state. Using a @repeat value of anything other than
 * 0 will block the processor for the duration of the command.
 *
 * If @repeat is not 0, then the LEDs are reset to all off at the end
 * of the sequence.
 *
 * IN:  [1:cmd][1:led_state][1:repeat][1:on-time][1:off-time]
 * OUT: [1:retval][1:cmd]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ??       |      ???
 * ColorHug2      |      ??       |      ???
 * ColorHug+      |      ??       |      ???
 * ColorHugALS    |      ??       |      ???
 *
 * Since: 0.1.29
 **/
#define	CH_CMD_SET_LEDS				0x0e

/**
 * CH_CMD_GET_ILLUMINANTS:
 *
 * Get the illuminant state.
 *
 * IN:  [1:cmd]
 * OUT: [1:retval][1:cmd][1:illuminants]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ??       |      ??
 * ColorHug2      |      ??       |      ??
 * ColorHug+      |      ??       |      ???
 * ColorHugALS    |      ??       |      ??
 *
 * Since: 1.3.4
 **/
#define	CH_CMD_GET_ILLUMINANTS			0x15

/**
 * CH_CMD_SET_ILLUMINANTS:
 *
 * Set the illuminants.
 *
 * IN:  [1:cmd][1:illuminant]
 * OUT: [1:retval][1:cmd]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ??       |      ??
 * ColorHug2      |      ??       |      ??
 * ColorHug+      |      ??       |      ???
 * ColorHugALS    |      ??       |      ??
 *
 * Since: 1.3.4
 **/
#define	CH_CMD_SET_ILLUMINANTS			0x16

/**
 * CH_CMD_GET_DARK_OFFSETS:
 *
 * Get the dark offsets.
 *
 * IN:  [1:cmd]
 * OUT: [1:retval][1:cmd][2:red][2:green][2:blue]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ??       |      ???
 * ColorHug2      |      ??       |      ??
 * ColorHug+      |      ??       |      ???
 * ColorHugALS    |      ??       |      ??
 *
 * Since: 0.1.29
 **/
#define	CH_CMD_GET_DARK_OFFSETS			0x0f

/**
 * CH_CMD_SET_DARK_OFFSETS:
 *
 * Set the dark offsets for use when taking samples when the measure
 * mode is FREQUENCY. When the measure mode is DURATION these values
 * have no effect.
 *
 * IN:  [1:cmd][2:red][2:green][2:blue]
 * OUT: [1:retval][1:cmd]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ??       |      ???
 * ColorHug2      |      ??       |      ??
 * ColorHug+      |      ??       |      ???
 * ColorHugALS    |      ??       |      ??
 *
 * Since: 0.1.29
 **/
#define	CH_CMD_SET_DARK_OFFSETS			0x10

/**
 * CH_CMD_GET_OWNER_NAME:
 *
 * Get User's Name
 *
 * IN:  [1:cmd]
 * OUT: [1:retval][1:cmd][60:owner-name]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ??       |      ???
 * ColorHug2      |      ??       |      ???
 * ColorHug+      |      ??       |      ???
 * ColorHugALS    |      ??       |      ??
 *
 * Since: 0.1.29
 **/
#define	CH_CMD_GET_OWNER_NAME			0x11

/**
 * CH_CMD_SET_OWNER_NAME:
 *
 * Set User's Name
 *
 * IN:  [1:cmd][60:owner-name]
 * OUT: [1:retval][1:cmd]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ??       |      ???
 * ColorHug2      |      ??       |      ???
 * ColorHug+      |      ??       |      ???
 * ColorHugALS    |      ??       |      ??
 *
 * Since: 0.1.29
 **/
#define	CH_CMD_SET_OWNER_NAME			0x12

/**
 * CH_CMD_GET_OWNER_EMAIL:
 *
 * Get User's Email Address
 *
 * IN:  [1:cmd]
 * OUT: [1:retval][1:cmd][60:owner-email]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ??       |      ???
 * ColorHug2      |      ??       |      ???
 * ColorHug+      |      ??       |      ???
 * ColorHugALS    |      ??       |      ??
 *
 * Since: 0.1.29
 **/
#define	CH_CMD_GET_OWNER_EMAIL			0x13

/**
 * CH_CMD_SET_OWNER_EMAIL:
 *
 * Set User's Email Address
 *
 * IN:  [1:cmd][60:owner-email]
 * OUT: [1:retval][1:cmd]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ??       |      ???
 * ColorHug2      |      ??       |      ???
 * ColorHug+      |      ??       |      ???
 * ColorHugALS    |      ??       |      ??
 *
 * Since: 0.1.29
 **/
#define	CH_CMD_SET_OWNER_EMAIL			0x14

/**
 * CH_CMD_WRITE_EEPROM:
 *
 * Write values to EEPROM.
 *
 * IN:  [1:cmd][8:eeprom_magic]
 * OUT: [1:retval][1:cmd]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ??       |      ???
 * ColorHug2      |      ??       |      ???
 * ColorHug+      |      ??       |      ???
 * ColorHugALS    |      ??       |      ??
 *
 * Since: 0.1.29
 **/
#define	CH_CMD_WRITE_EEPROM			0x20

/**
 * CH_CMD_TAKE_READING_RAW:
 *
 * Take a raw reading.
 *
 * IN:  [1:cmd]
 * OUT: [1:retval][1:cmd][4:count]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ??       |      ???
 * ColorHug2      |      ??       |      ??
 * ColorHug+      |      ??       |      ???
 * ColorHugALS    |      ??       |      ???
 *
 * Since: 0.1.29
 **/
#define	CH_CMD_TAKE_READING_RAW			0x21

/**
 * CH_CMD_TAKE_READINGS:
 *
 * Take a reading taking into account just dark offsets.
 * All of @red, @green and @blue are packed float values.
 *
 * This command is useful if you want to do an ambient reading.
 *
 * IN:  [1:cmd]
 * OUT: [1:retval][1:cmd][4:red][4:green][4:blue]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ??       |      ???
 * ColorHug2      |      ??       |      ???
 * ColorHug+      |      ??       |      ???
 * ColorHugALS    |      ??       |      ??
 *
 * Since: 0.1.29
 **/
#define	CH_CMD_TAKE_READINGS			0x22

/**
 * CH_CMD_TAKE_READING_XYZ:
 *
 * Take a reading taking into account:
 *  1. dark offsets
 *  2. the calibration matrix
 *
 * If the calibration index > %CH_CALIBRATION_MAX then the calibration
 * map is used to find the default calibration index to use.
 *
 * If the calibration index is set to %CH_CALIBRATION_SPECTRAL then the
 * spectral hardware is used if it is available. The CIE 1931 luminosity
 * function data is used by default.
 *
 * IN:  [1:cmd][2:calibration-index]
 * OUT: [1:retval][1:cmd][4:red][4:green][4:blue]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ??       |      ???
 * ColorHug2      |      ??       |      ???
 * ColorHug+      |      ??       |      ???
 * ColorHugALS    |      ??       |      ??
 *
 * Since: 0.1.29
 **/
#define	CH_CMD_TAKE_READING_XYZ			0x23

/**
 * CH_CMD_TAKE_READING_SPECTRAL:
 *
 * Takes a spectral reading putting %CH_CCD_SPECTRAL_RESOLUTION uint16_t values
 * (typically 7296 bytes) in SRAM.
 * The values are scaled from 0x0000 to 0x03ff and correspond to the actual
 * signal amplitude once Vref- and Vref+ have been taken into account.
 *
 * IN:  [1:cmd]
 * OUT: [1:retval][1:cmd][4:addr]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ??       |      ??
 * ColorHug2      |      ??       |      ??
 * ColorHug+      |      ??       |      ???
 * ColorHugALS    |      ??       |      ??
 *
 * Since: 0.1.31
 **/
#define	CH_CMD_TAKE_READING_SPECTRAL		0x55

/**
 * CH_CMD_GET_ADC_CALIBRATION_POS:
 *
 * Gets the value of the Vref+ ADC adjustment.
 * @vref is a packed float.
 *
 * IN:  [1:cmd]
 * OUT: [1:retval][1:cmd][4:vref]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ??       |      ??
 * ColorHug2      |      ??       |      ??
 * ColorHug+      |      ??       |      ???
 * ColorHugALS    |      ??       |      ??
 *
 * Since: 0.1.31
 **/
#define	CH_CMD_GET_ADC_CALIBRATION_POS		0x51

/**
 * CH_CMD_GET_ADC_CALIBRATION_NEG:
 *
 * Gets the value of the Vref- ADC adjustment.
 * @vref is a packed float.
 *
 * IN:  [1:cmd]
 * OUT: [1:retval][1:cmd][4:vref]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ??       |      ??
 * ColorHug2      |      ??       |      ??
 * ColorHug+      |      ??       |      ???
 * ColorHugALS    |      ??       |      ??
 *
 * Since: 0.1.31
 **/
#define	CH_CMD_GET_ADC_CALIBRATION_NEG		0x52

/**
 * CH_CMD_GET_CCD_CALIBRATION:
 *
 * Gets the spectral indexes for the RGB calibration which are values between 0
 * and %CH_CCD_SPECTRAL_RESOLUTION pointing to the dominant peak for the color.
 * Red is nominally 625nm, green 520nm and blue 465nm.
 *
 * IN:  [1:cmd]
 * OUT: [1:retval][1:cmd][2:red-idx][2:green-idx][2:blue-idx]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ??       |      ??
 * ColorHug2      |      ??       |      ??
 * ColorHug+      |      ??       |      ???
 * ColorHugALS    |      ??       |      ??
 *
 * Since: 0.1.31
 **/
#define	CH_CMD_GET_CCD_CALIBRATION		0x53

/**
 * CH_CMD_SET_CCD_CALIBRATION:
 *
 * Sets the spectral indexes for the RGB calibration.
 *
 * IN:  [1:cmd][2:red-idx][2:green-idx][2:blue-idx]
 * OUT: [1:retval][1:cmd]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ??       |      ??
 * ColorHug2      |      ??       |      ??
 * ColorHug+      |      ??       |      ???
 * ColorHugALS    |      ??       |      ??
 *
 * Since: 0.1.31
 **/
#define	CH_CMD_SET_CCD_CALIBRATION		0x54

/**
 * CH_CMD_RESET:
 *
 * Reset the processor.
 *
 * IN:  [1:cmd]
 * OUT: [1:retval][1:cmd] (but with success the device will disconnect)
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ???       |      ???
 * ColorHug2      |      ???       |      ???
 * ColorHug+      |      ???       |      ???
 * ColorHugALS    |      ???       |      ???
 *
 * Since: 0.1.29
 **/
#define	CH_CMD_RESET				0x24

/**
 * CH_CMD_READ_FLASH:
 *
 * Read in raw data from the flash memory.
 *
 * IN:  [1:cmd][2:address][1:length]
 * OUT: [1:retval][1:cmd][1:checksum][1-60:data]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ???       |      ??
 * ColorHug2      |      ???       |      ??
 * ColorHug+      |      ???       |      ??
 * ColorHugALS    |      ???       |      ??
 *
 * Since: 0.1.29
 **/
#define	CH_CMD_READ_FLASH			0x25

/**
 * CH_CMD_ERASE_FLASH:
 *
 * Erases flash memory before a write is done.
 * Erasing flash can only be done in 1k byte chunks and should be
 * aligned to 1k.
 *
 * IN:  [1:cmd][2:address][2:length]
 * OUT: [1:retval][1:cmd]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ???       |      ??
 * ColorHug2      |      ???       |      ??
 * ColorHug+      |      ???       |      ??
 * ColorHugALS    |      ???       |      ??
 *
 * Since: 0.1.29
 **/
#define	CH_CMD_ERASE_FLASH			0x29

/**
 * CH_CMD_WRITE_FLASH:
 *
 * Write raw data to the flash memory. You can only write aligned to
 * a 32 byte boundary, and you must flush any incomplete 64 byte block.
 *
 * IN:  [1:cmd][2:address][1:length][1:checksum][1-32:data]
 * OUT: [1:retval][1:cmd]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ???       |      ??
 * ColorHug2      |      ???       |      ??
 * ColorHug+      |      ???       |      ??
 * ColorHugALS    |      ???       |      ??
 *
 * Since: 0.1.29
 **/
#define	CH_CMD_WRITE_FLASH			0x26

/**
 * CH_CMD_BOOT_FLASH:
 *
 * Boot into to the flash memory.
 *
 * IN:  [1:cmd]
 * OUT: [1:retval][1:cmd]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ???       |      ??
 * ColorHug2      |      ???       |      ??
 * ColorHug+      |      ???       |      ??
 * ColorHugALS    |      ???       |      ??
 *
 * Since: 0.1.29
 **/
#define	CH_CMD_BOOT_FLASH			0x27

/**
 * CH_CMD_SET_FLASH_SUCCESS:
 *
 * Sets the result of the firmware flashing. The idea of this command
 * is that the flashing interaction is thus:
 *
 * 1.	Reset()			device goes to bootloader mode
 * 2.	SetFlashSuccess(FALSE)
 * 3.	WriteFlash($data)
 * 4.	ReadFlash($data)	to verify
 * 5.	BootFlash()		switch to program mode
 * 6.	SetFlashSuccess(TRUE)
 *
 * The idea is that we only set the success FALSE from the bootoloader
 * to indicate that on booting we should not boot into the program.
 * We can only set the success true from the *new* program code so as
 * to verify that the new program boots, and can accept HID commands.
 *
 * IN:  [1:cmd][1:success]
 * OUT: [1:retval][1:cmd]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ???       |      ???
 * ColorHug2      |      ???       |      ???
 * ColorHug+      |      ???       |      ???
 * ColorHugALS    |      ???       |      ???
 *
 * Different values of @success are permitted in each mode.
 *
 * Since: 0.1.29
 **/
#define	CH_CMD_SET_FLASH_SUCCESS		0x28

/**
 * CH_CMD_GET_PRE_SCALE:
 *
 * Get the pre XYZ scaling constant. @scale is a packed float.
 *
 * IN:  [1:cmd]
 * OUT: [1:retval][1:cmd][4:scale]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ??       |      ???
 * ColorHug2      |      ??       |      ??
 * ColorHug+      |      ??       |      ??
 * ColorHugALS    |      ??       |      ??
 *
 * Since: 0.1.29
 **/
#define	CH_CMD_GET_PRE_SCALE			0x2c

/**
 * CH_CMD_SET_PRE_SCALE:
 *
 * Set the pre XYZ scaling constant. @scale is a packed float.
 *
 * IN:  [1:cmd][4:scale]
 * OUT: [1:retval][1:cmd]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ??       |      ???
 * ColorHug2      |      ??       |      ??
 * ColorHug+      |      ??       |      ??
 * ColorHugALS    |      ??       |      ??
 *
 * Since: 0.1.29
 **/
#define	CH_CMD_SET_PRE_SCALE			0x2d

/**
 * CH_CMD_GET_POST_SCALE:
 *
 * Get the post XYZ scaling constant. @scale is a packed float.
 *
 * IN:  [1:cmd]
 * OUT: [1:retval][1:cmd][4:scale]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ??       |      ???
 * ColorHug2      |      ??       |      ??
 * ColorHug+      |      ??       |      ??
 * ColorHugALS    |      ??       |      ??
 *
 * Since: 0.1.29
 **/
#define	CH_CMD_GET_POST_SCALE			0x2a

/**
 * CH_CMD_SET_POST_SCALE:
 *
 * Set the post XYZ scaling constant. @scale is a packed float.
 *
 * IN:  [1:cmd][4:scale]
 * OUT: [1:retval][1:cmd]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ??       |      ???
 * ColorHug2      |      ??       |      ??
 * ColorHug+      |      ??       |      ??
 * ColorHugALS    |      ??       |      ??
 *
 * Since: 0.1.29
 **/
#define	CH_CMD_SET_POST_SCALE			0x2b

/**
 * CH_CMD_GET_CALIBRATION_MAP:
 *
 * Get the mappings from default calibration type to calibration
 * indexes.
 *
 * The calibration types are as follows:
 * LCD		= 0
 * CRT		= 1
 * Projector	= 2
 * LED		= 3
 * Custom1	= 4
 * Custom2	= 5
 *
 * In the future CustomX may be renamed to another display technology,
 * e.g. e-ink.
 *
 * IN:  [1:cmd]
 * OUT: [1:retval][1:cmd][6*2:types]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ??       |      ???
 * ColorHug2      |      ??       |      ???
 * ColorHug+      |      ??       |      ??
 * ColorHugALS    |      ??       |      ??
 *
 * Since: 0.1.29
 **/
#define	CH_CMD_GET_CALIBRATION_MAP		0x2e

/**
 * CH_CMD_SET_CALIBRATION_MAP:
 *
 * Set the calibration type to index map.
 *
 * IN:  [1:cmd][6*2:types]
 * OUT: [1:retval][1:cmd]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ??       |      ???
 * ColorHug2      |      ??       |      ???
 * ColorHug+      |      ??       |      ??
 * ColorHugALS    |      ??       |      ??
 *
 * Since: 0.1.29
 **/
#define	CH_CMD_SET_CALIBRATION_MAP		0x2f

/**
 * CH_CMD_GET_HARDWARE_VERSION:
 *
 * Get the hardware version.
 *
 * The hardware versions are as follows:
 * 0x00		= Pre-production hardware
 * 0x01		= ColorHug
 * 0x02		= ColorHug2
 * 0x03		= ColorHug+
 * 0x04		= ColorHugALS
 * 0x05-0x0f	= Reserved for future use
 *
 * IN:  [1:cmd]
 * OUT: [1:retval][1:cmd][1:hw_version]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ???       |      ???
 * ColorHug2      |      ???       |      ???
 * ColorHug+      |      ???       |      ???
 * ColorHugALS    |      ???       |      ???
 *
 * Since: 0.1.29
 **/
#define	CH_CMD_GET_HARDWARE_VERSION		0x30

/**
 * CH_CMD_TAKE_READING_ARRAY:
 *
 * Takes 30 raw samples and returns them in an array.
 *
 * This command can be used to find the optimum delay between patches
 * by showing a black sample area, then white, and then using this
 * command to find out how long the actual hardware delay is.
 *
 * It can also be used to find out how stable the device or output is
 * over a small amount of time, typically ~2.5 seconds for the maximum
 * integral time.
 *
 * IN:  [1:cmd]
 * OUT: [1:retval][1:cmd][30:reading_array]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ??       |      ???
 * ColorHug2      |      ??       |      ??
 * ColorHug+      |      ??       |      ??
 * ColorHugALS    |      ??       |      ??
 *
 * Since: 0.1.29
 **/
#define	CH_CMD_TAKE_READING_ARRAY		0x31

/**
 * CH_CMD_SET_PCB_ERRATA:
 *
 * Sets the board errata value. Board errata is used to correct swapped
 * LEDs and any future problems discovered that only affect some batches
 * of hardware version 1.
 *
 * The errata bitmask is as follows:
 * 0x00		= No errata for this PCB
 * 0x01		= Leds are swapped
 * 0x02-0xffff	= Reserved for future use
 *
 * IN:  [1:cmd][2:pcb_errata]
 * OUT: [1:retval][1:cmd]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ??       |      ???
 * ColorHug2      |      ??       |      ???
 * ColorHug+      |      ??       |      ???
 * ColorHugALS    |      ??       |      ??
 *
 * Since: 0.1.29
 **/
#define	CH_CMD_SET_PCB_ERRATA			0x32

/**
 * CH_CMD_GET_PCB_ERRATA:
 *
 * Gets the board errata value.
 *
 * IN:  [1:cmd]
 * OUT: [1:retval][1:cmd][2:pcb_errata]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ??       |      ???
 * ColorHug2      |      ??       |      ???
 * ColorHug+      |      ??       |      ???
 * ColorHugALS    |      ??       |      ??
 *
 * Since: 0.1.29
 **/
#define	CH_CMD_GET_PCB_ERRATA			0x33

/**
 * CH_CMD_SET_REMOTE_HASH:
 *
 * Sets the remote SHA1 hash of the profile. This is designed to
 * be used by the calibration program to indicate the key which allows
 * the completed profile to be found from a public web service.
 *
 * IN:  [1:cmd][20:sha1_hash]
 * OUT: [1:retval][1:cmd]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ??       |      ???
 * ColorHug2      |      ??       |      ???
 * ColorHug+      |      ??       |      ???
 * ColorHugALS    |      ??       |      ??
 *
 * Since: 0.1.29
 **/
#define	CH_CMD_SET_REMOTE_HASH			0x34

/**
 * CH_CMD_GET_REMOTE_HASH:
 *
 * Gets the remote hash which is used to get the last profile saved
 * to a public web service.
 *
 * IN:  [1:cmd]
 * OUT: [1:retval][1:cmd][20:sha1_hash]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ??       |      ???
 * ColorHug2      |      ??       |      ???
 * ColorHug+      |      ??       |      ???
 * ColorHugALS    |      ??       |      ??
 *
 * Since: 0.1.29
 **/
#define	CH_CMD_GET_REMOTE_HASH			0x35

/**
 * CH_CMD_SET_MEASURE_MODE:
 *
 * Sets the measurement mode. The mode can either be frequency or pulse
 * duration. The former is well tested, but the latter is much more
 * precise.
 *
 * IN:  [1:cmd][1:measure_mode]
 * OUT: [1:retval][1:cmd]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ??       |      ???
 * ColorHug2      |      ??       |      ??
 * ColorHug+      |      ??       |      ??
 * ColorHugALS    |      ??       |      ??
 *
 * Since: 0.1.29
 **/
#define	CH_CMD_SET_MEASURE_MODE			0x36

/**
 * CH_CMD_GET_MEASURE_MODE:
 *
 * Gets the measurement mode.
 *
 * IN:  [1:cmd]
 * OUT: [1:retval][1:cmd][1:measure_mode]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ??       |      ???
 * ColorHug2      |      ??       |      ??
 * ColorHug+      |      ??       |      ??
 * ColorHugALS    |      ??       |      ??
 *
 * Since: 0.1.29
 **/
#define	CH_CMD_GET_MEASURE_MODE			0x37

/**
 * CH_CMD_READ_SRAM:
 *
 * Read in raw data from the SRAM memory.
 *
 * PROTOCOLv1:
 * IN:  [1:cmd][2:address][1:length]
 * OUT: [1:retval][1:cmd][1-60:data]
 *
 * PROTOCOLv2:
 * bRequest:   [cmd]
 * wValue:     [address-index/64]
 * wIndex:     interface
 * wLength:    0x64
 * Direction:  DEVICE->HOST
 * Data:       [64:DATA]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ??       |      ??
 * ColorHug2      |      ??       |      ???
 * ColorHug+      |      ??       |      ???
 * ColorHugALS    |      ??       |      ??
 *
 * Since: 0.1.29
 **/
#define	CH_CMD_READ_SRAM			0x38

/**
 * CH_CMD_WRITE_SRAM:
 *
 * Write raw data to the SRAM memory.
 *
 * IN:  [1:cmd][2:address][1:length][1-60:data]
 * OUT: [1:retval][1:cmd]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ??       |      ??
 * ColorHug2      |      ??       |      ???
 * ColorHug+      |      ??       |      ???
 * ColorHugALS    |      ??       |      ??
 *
 * Since: 0.1.29
 **/
#define	CH_CMD_WRITE_SRAM			0x39

/**
 * CH_CMD_GET_TEMPERATURE:
 *
 * Gets the temperature of the sensor in degrees celsius
 *
 * IN:  [1:cmd]
 * OUT: [1:retval][1:cmd][4:temperature]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ??       |      ??
 * ColorHug2      |      ??       |      ???
 * ColorHug+      |      ??       |      ???
 * ColorHugALS    |      ??       |      ??
 *
 * Since: 0.1.29
 **/
#define	CH_CMD_GET_TEMPERATURE			0x3b

/**
 * CH_CMD_GET_DAC_VALUE:
 *
 * Get the DAC value. @scale is a packed float, where 1.0f is 3.3V
 *
 * IN:  [1:cmd]
 * OUT: [1:retval][1:cmd][4:value]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ??       |      ??
 * ColorHug2      |      ??       |      ??
 * ColorHug+      |      ??       |      ???
 * ColorHugALS    |      ??       |      ??
 *
 * Since: 1.1.6
 **/
#define	CH_CMD_GET_DAC_VALUE			0x3c

/**
 * CH_CMD_SET_DAC_VALUE:
 *
 * Set the DAC value. @scale is a packed float, where 1.0f is 3.3V
 *
 * IN:  [1:cmd][4:value]
 * OUT: [1:retval][1:cmd]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ??       |      ??
 * ColorHug2      |      ??       |      ??
 * ColorHug+      |      ??       |      ???
 * ColorHugALS    |      ??       |      ??
 *
 * Since: 1.1.6
 **/
#define	CH_CMD_SET_DAC_VALUE			0x3d

/**
 * CH_CMD_SELF_TEST:
 *
 * Tests the device by trying to get a non-zero reading from each
 * color channel.
 *
 * IN:  [1:cmd]
 * OUT: [1:retval][1:cmd]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ???       |      ???
 * ColorHug2      |      ???       |      ???
 * ColorHug+      |      ???       |      ???
 * ColorHugALS    |      ???       |      ??
 *
 * Since: 0.1.29
 **/
#define	CH_CMD_SELF_TEST			0x40

/**
 * CH_CMD_LOAD_SRAM:
 *
 * Load the SRAM from the EEPROM.
 *
 * PROTOCOLv2:
 * bRequest:   [cmd]
 * wValue:     0x00
 * wIndex:     interface
 * wLength:    0x00
 * Direction:  DEVICE->HOST
 * Data:       [1:error][1:cmd]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ??       |      ??
 * ColorHug2      |      ??       |      ??
 * ColorHug+      |      ??       |      ???
 * ColorHugALS    |      ??       |      ??
 *
 * Since: 0.1.29
 **/
#define	CH_CMD_LOAD_SRAM			0x41

/**
 * CH_CMD_SAVE_SRAM:
 *
 * Save the SRAM to the EEPROM.
 *
 * PROTOCOLv2:
 * bRequest:   [cmd]
 * wValue:     0x00
 * wIndex:     interface
 * wLength:    0x00
 * Direction:  DEVICE->HOST
 * Data:       [1:error][1:cmd]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ??       |      ??
 * ColorHug2      |      ??       |      ??
 * ColorHug+      |      ??       |      ???
 * ColorHugALS    |      ??       |      ??
 *
 * Since: 0.1.29
 **/
#define	CH_CMD_SAVE_SRAM			0x42

/**
 * CH_CMD_GET_ERROR:
 *
 * Gets any recorded error from the device.
 *
 * PROTOCOLv2:
 * bRequest:   [cmd]
 * wValue:     0x00
 * wIndex:     interface
 * wLength:    0x00
 * Direction:  DEVICE->HOST
 * Data:       [1:error][1:cmd]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ??       |      ??
 * ColorHug2      |      ??       |      ??
 * ColorHug+      |      ??       |      ???
 * ColorHugALS    |      ??       |      ??
 *
 * Since: 1.3.1
 **/
#define	CH_CMD_GET_ERROR			0x60

/**
 * CH_CMD_CLEAR_ERROR:
 *
 * Clears any recorded error on the device.
 *
 * PROTOCOLv2:
 * bRequest:   [cmd]
 * wValue:     0x00
 * wIndex:     interface
 * wLength:    0x00
 * Direction:  DEVICE->HOST
 * Data:       []
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ??       |      ??
 * ColorHug2      |      ??       |      ??
 * ColorHug+      |      ??       |      ???
 * ColorHugALS    |      ??       |      ??
 *
 * Since: 1.3.1
 **/
#define	CH_CMD_CLEAR_ERROR			0x61

/**
 * CH_CMD_SET_CRYPTO_KEY:
 *
 * Sets the 128 bit encryption key for the device.
 *
 * PROTOCOLv2:
 * bRequest:   [cmd]
 * wValue:     0x00
 * wIndex:     interface
 * wLength:    0x00
 * Direction:  DEVICE->HOST
 * Data:       [4:key0][4:key1][4:key2][4:key3]
 *
 * This command is available under these conditions:
 *
 *                |  Bootloader  |  Firmware
 * ---------------+--------------+-----------
 * ColorHug       |      ??       |      ??
 * ColorHug2      |      ??       |      ??
 * ColorHug+      |      ??       |      ???
 * ColorHugALS    |      ??       |      ??
 *
 * Since: 1.3.1
 **/
#define	CH_CMD_SET_CRYPTO_KEY			0x70

/* the values here are not really API */
#define	CH_EP0_TRANSFER_SIZE			64
#define	CH_EP0_TRANSFER_SIZE_V2			0x400	/* since 1.3.4 */

/* secret code */
#define	CH_WRITE_EEPROM_MAGIC			"Un1c0rn2"
#define	CH_FIRMWARE_ID_TOKEN1			"40338ceb"
#define	CH_FIRMWARE_ID_TOKEN2			"2082b5e0"
#define	CH_FIRMWARE_ID_TOKEN_ALS		"84f40464"	/* since 1.2.9 */
#define	CH_FIRMWARE_ID_TOKEN_PLUS		"6d6f05a9"

#define CH_DEVICE_GUID_COLORHUG			"40338ceb-b966-4eae-adae-9c32edfcc484"	/* since 1.2.9 */
#define CH_DEVICE_GUID_COLORHUG2		"2082b5e0-7a64-478a-b1b2-e3404fab6dad"	/* since 1.2.9 */
#define CH_DEVICE_GUID_COLORHUG_ALS		"84f40464-9272-4ef7-9399-cd95f12da696"	/* since 1.2.9 */
#define CH_DEVICE_GUID_COLORHUG_PLUS		"6d6f05a9-3ecb-43a2-bcbb-3844f1825366"	/* since 1.2.9 */

/* input and output buffer offsets */
#define	CH_BUFFER_INPUT_CMD			0x00
#define	CH_BUFFER_INPUT_DATA			0x01
#define	CH_BUFFER_OUTPUT_RETVAL			0x00
#define	CH_BUFFER_OUTPUT_CMD			0x01
#define	CH_BUFFER_OUTPUT_DATA			0x02

/* where the custom firmware is stored */
#define CH_EEPROM_ADDR_RUNCODE			0x4000
#define CH_EEPROM_ADDR_RUNCODE_ALS		0x2000		/* since 1.2.9 */

/* the number of useful samples from the the CCD */
#define CH_CCD_SPECTRAL_RESOLUTION		1024

/* although each calibration can be stored in 60 bytes,
 * we use a full 64 byte block */
#define	CH_CALIBRATION_MAX			64	/* so finishes at device params */
#define	CH_CALIBRATION_SPECTRAL			0xffff
#define	CH_CALIBRATION_DESCRIPTION_LEN		23	/* 60 - (9*4) - 1 */

/* the supported calibration types bitfield */
#define	CH_CALIBRATION_TYPE_LCD			0x01
#define	CH_CALIBRATION_TYPE_CRT			0x02
#define	CH_CALIBRATION_TYPE_PROJECTOR		0x04
#define	CH_CALIBRATION_TYPE_LED			0x08
#define	CH_CALIBRATION_TYPE_ALL			0xff

/* approximate sample times */
#define CH_INTEGRAL_TIME_VALUE_5MS		0x0300
#define CH_INTEGRAL_TIME_VALUE_50MS		0x1f00
#define CH_INTEGRAL_TIME_VALUE_100MS		0x3a00
#define CH_INTEGRAL_TIME_VALUE_200MS		0x7500
#define CH_INTEGRAL_TIME_VALUE_MAX		0xffff

/* flash constants */
#define	CH_FLASH_ERASE_BLOCK_SIZE		0x400	/* 1024 */
#define	CH_FLASH_WRITE_BLOCK_SIZE		0x040	/* 64 */
#define	CH_FLASH_TRANSFER_BLOCK_SIZE		0x020	/* 32 */
#define	CH_FLASH_RECONNECT_TIMEOUT		5000	/* ms */

/* calibration remapping contants */
#define	CH_CALIBRATION_INDEX_FACTORY_ONLY	0x00
#define	CH_CALIBRATION_INDEX_LCD		(CH_CALIBRATION_MAX + 0)
#define	CH_CALIBRATION_INDEX_CRT		(CH_CALIBRATION_MAX + 1)
#define	CH_CALIBRATION_INDEX_PROJECTOR		(CH_CALIBRATION_MAX + 2)
#define	CH_CALIBRATION_INDEX_LED		(CH_CALIBRATION_MAX + 3)
#define	CH_CALIBRATION_INDEX_MAX		0x06

/* which color to select */
typedef enum {
	CH_COLOR_SELECT_RED,
	CH_COLOR_SELECT_WHITE,
	CH_COLOR_SELECT_BLUE,
	CH_COLOR_SELECT_GREEN
} ChColorSelect;

/* Led colors: possible bitfield values */
typedef enum {
	CH_STATUS_LED_GREEN	= 1 << 0,
	CH_STATUS_LED_RED	= 1 << 1,
	CH_STATUS_LED_BLUE	= 1 << 2	/* Since: 0.1.29 */
} ChStatusLed;

/* Illuminants: possible bitfield values */
typedef enum {
	CH_ILLUMINANT_NONE	= 0,		/* Since: 1.3.4 */
	CH_ILLUMINANT_A		= 1 << 0,	/* Since: 1.3.4 */
	CH_ILLUMINANT_UV	= 1 << 1,	/* Since: 1.3.4 */
	/*< private >*/
	CH_ILLUMINANT_LAST
} ChIlluminant;

/* what frequency divider to use */
typedef enum {
	CH_FREQ_SCALE_0,
	CH_FREQ_SCALE_20,
	CH_FREQ_SCALE_2,
	CH_FREQ_SCALE_100
} ChFreqScale;

/* fatal error morse code */
typedef enum {
	CH_ERROR_NONE,
	CH_ERROR_UNKNOWN_CMD,
	CH_ERROR_WRONG_UNLOCK_CODE,
	CH_ERROR_NOT_IMPLEMENTED,
	CH_ERROR_UNDERFLOW_SENSOR,
	CH_ERROR_NO_SERIAL,
	CH_ERROR_WATCHDOG,
	CH_ERROR_INVALID_ADDRESS,
	CH_ERROR_INVALID_LENGTH,
	CH_ERROR_INVALID_CHECKSUM,
	CH_ERROR_INVALID_VALUE,
	CH_ERROR_UNKNOWN_CMD_FOR_BOOTLOADER,
	CH_ERROR_NO_CALIBRATION,
	CH_ERROR_OVERFLOW_MULTIPLY,
	CH_ERROR_OVERFLOW_ADDITION,
	CH_ERROR_OVERFLOW_SENSOR,
	CH_ERROR_OVERFLOW_STACK,
	CH_ERROR_DEVICE_DEACTIVATED,
	CH_ERROR_INCOMPLETE_REQUEST,
	CH_ERROR_SELF_TEST_SENSOR,
	CH_ERROR_SELF_TEST_RED,
	CH_ERROR_SELF_TEST_GREEN,
	CH_ERROR_SELF_TEST_BLUE,
	CH_ERROR_SELF_TEST_COLOR_SELECT,
	CH_ERROR_SELF_TEST_MULTIPLIER,
	CH_ERROR_INVALID_CALIBRATION,
	CH_ERROR_SRAM_FAILED,
	CH_ERROR_OUT_OF_MEMORY,
	CH_ERROR_SELF_TEST_TEMPERATURE,
	CH_ERROR_SELF_TEST_I2C,
	CH_ERROR_SELF_TEST_ADC_VDD,
	CH_ERROR_SELF_TEST_ADC_VSS,
	CH_ERROR_SELF_TEST_ADC_VREF,
	CH_ERROR_I2C_SLAVE_ADDRESS,
	CH_ERROR_I2C_SLAVE_CONFIG,
	CH_ERROR_SELF_TEST_EEPROM,	/* since 1.2.9 */
	/*< private >*/
	CH_ERROR_LAST
} ChError;

/* the measure mode */
typedef enum {
	CH_MEASURE_MODE_FREQUENCY,
	CH_MEASURE_MODE_DURATION
} ChMeasureMode;

/* any problems with the PCB */
typedef enum {
	CH_PCB_ERRATA_NONE		= 0,
	CH_PCB_ERRATA_SWAPPED_LEDS	= 1 << 0,
	CH_PCB_ERRATA_NO_WELCOME	= 1 << 1,
	/*< private >*/
	CH_PCB_ERRATA_LAST		= 1 << 2
} ChPcbErrata;

typedef enum {
	CH_DEVICE_MODE_UNKNOWN,
	CH_DEVICE_MODE_LEGACY,
	CH_DEVICE_MODE_BOOTLOADER,
	CH_DEVICE_MODE_FIRMWARE,
	CH_DEVICE_MODE_BOOTLOADER_PLUS,
	CH_DEVICE_MODE_FIRMWARE_PLUS,
	CH_DEVICE_MODE_FIRMWARE2,	/* since 1.2.2 */
	CH_DEVICE_MODE_BOOTLOADER2,	/* since 1.2.3 */
	CH_DEVICE_MODE_BOOTLOADER_ALS,	/* since 1.2.9 */
	CH_DEVICE_MODE_FIRMWARE_ALS,	/* since 1.2.9 */
	/*< private >*/
	CH_DEVICE_MODE_LAST
} ChDeviceMode;

typedef enum {
	CH_SPECTRUM_KIND_RAW		= 0x00,	/* since 1.3.4 */
	CH_SPECTRUM_KIND_DARK_CAL	= 0x01,	/* since 1.3.4 */
	CH_SPECTRUM_KIND_TEMP_CAL	= 0x02,	/* since 1.3.4 */
	CH_SPECTRUM_KIND_IRRADIANCE_CAL	= 0x03,	/* since 1.3.4 */
	CH_SPECTRUM_KIND_LAST
} ChSpectrumKind;

typedef guint8 ChCmd;

/* prototypes */
const gchar	*ch_strerror			(ChError	 error_enum);
const gchar	*ch_command_to_string		(ChCmd		 cmd);
const gchar	*ch_multiplier_to_string	(ChFreqScale	 multiplier);
const gchar	*ch_color_select_to_string	(ChColorSelect	 color_select);
const gchar	*ch_measure_mode_to_string	(ChMeasureMode	 measure_mode);
const gchar	*ch_device_mode_to_string	(ChDeviceMode	 device_mode);
ChDeviceMode	 ch_device_mode_from_firmware	(const guint8	*data,
						 gsize		 data_len);

G_END_DECLS

#endif
