# Smart-E-Bike
Codes for communication of Node-MCU and Arduino Nano

The first file contains codes for transmitting data to Arduino Nano from ESP-8266 using I2C protocol which is received in wireless form from end devices.
File Name: TX_NODE-MCU.ino
The second file contains codes for transmitting data from Arduino Nano module to ESP-8266 module along with sending the received data to Google firebase
File Name: RX_NODE-MCU.ino
The process is divided into two steps:
Step-1:
The first step is to make first ESP-8266 work as an access point(mediator) to collect data from E-Bikes(end devices) and it sends the data to Arduino Nano using I2c Protocol .This ESP-8266 module cannot directly send data to Firebase as it is acting as Access Point and it does not have internet. So we send the received data to Arduino Nano.
Step-2:
The Arduino Nano will send the received data to another ESP-8266 using I2C protocol which has internet, so that it can directly send data to Firebase database. The process is a bit complicated  but at that point of time we figured out this way only.

Note* In the first step when the Access Point receives the data from end devices, it is a wireless communication and its code is written in TX_NODE-MCU.ino file.
