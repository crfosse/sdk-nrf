.. _i2c_scanner_sample:

i2c Scanner
##################

--- Disclaimer: this is not an official nRF Connect SDK example ---

This example shows how i2c can be enabled and used in the Zephyr environment for the nRF9160 and nRF5340. It is based on 
`this <https://github.com/sigurdnev/fw-nrfconnect-nrf/tree/master/samples/nrf9160/i2c_scanner>`_ sample. 

Overview
********

The sample scans for devices on the i2c bus, reporting back the address of detected devices. The used SDA and SCL pins, as well as the chosen i2c peripheral is 
configured in the .overlay file. Remeber to reflect the chosen i2c and twim peripheral in prj.conf and in main. 

Requirements
************

* One of the following development boards:

  * nRF9160DK or nRF5340PDK

Building and running
********************

.. |sample path| replace:: :file:`samples/nRF5340/i2c_scanner`