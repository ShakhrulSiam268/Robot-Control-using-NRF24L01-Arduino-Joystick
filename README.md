# Robot-Control-using-NRF24L01-Arduino-Joystick

This code uses "RF24" library. It's provided in the "NRF24" folder as zip file.
To install this library, open Arduino IDE, 
then Sketch >> Include Library >> Add .Zip Library and then browse to the Radiohead.zip file.

# Joystick Module:

![image](https://user-images.githubusercontent.com/61387093/130351918-a92c7770-552d-4ace-af42-a648783d49de.png)

# NRF24L01 Transceiver:

![image](https://user-images.githubusercontent.com/61387093/130351987-6ce888d8-cf18-4368-bb9d-3c5fadd8491d.png)

# Transmitter Code:
Use File Transmitter.ino
# Receiver Code:
Use File receiver_2_stepper_motor.ino

Pin connections NRF24L01 to Arduino 

MOSI --->> 11
MISO --->> 12
SCK --->> 13
VCC --->> 3.3V
GND --->> GND
CE --->> 8
CSN --->> 10

you can change CE & CSN if needed. Change code accordingly
