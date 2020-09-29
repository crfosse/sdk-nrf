/*
 * Copyright (c) 2018 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-BSD-5-Clause-Nordic
 */

#include <zephyr.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <drivers/i2c.h>
#include <device.h>

#define I2C_DEVICE "I2C_1"

/**@brief Recoverable BSD library error. */
void bsd_recoverable_error_handler(uint32_t err)
{
	printk("bsdlib recoverable error: %u\n", err);
}

void main(void)
{
	printk("The I2C test started\n");
    struct device *i2c_dev;
	int error;

    i2c_dev = device_get_binding(I2C_DEVICE);
    if (!i2c_dev) {
        printk("Binding failed.");
        return;
    }
    i2c_configure(i2c_dev, I2C_SPEED_SET(I2C_SPEED_STANDARD));

    printk("Value of NRF_TWIM1_NS->PSEL.SCL : %d \n",NRF_TWIM1->PSEL.SCL);
	printk("Value of NRF_TWIM1_NS->PSEL.SDA : %d \n",NRF_TWIM1->PSEL.SDA);
	printk("Value of NRF_TWIM1_NS->FREQUENCY: %d \n",NRF_TWIM1->FREQUENCY);
	printk("26738688 -> 100k\n");
        
    for (uint8_t i = 4; i <= 0x77; i++) {
		struct i2c_msg msgs[1];
		uint8_t dst = 1;

		msgs[0].buf = &dst;
		msgs[0].len = 1U;
		msgs[0].flags = I2C_MSG_WRITE | I2C_MSG_STOP;
		
		error = i2c_transfer(i2c_dev, &msgs[0], 1, i);
		if (error == 0) {
			printk("0x%2x FOUND\n", i);
		}
		else {
			printk("error %d \n", error);
		}
		
	}
}
