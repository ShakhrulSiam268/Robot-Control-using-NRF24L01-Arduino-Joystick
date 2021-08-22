/*
 This code uses "RF24" library. It's provided in the "NRF24" folder as zip file.
To install this library, open Arduino IDE, then Sketch >> Include Library >> Add .Zip Library
and then browse to the Radiohead.zip file.
 */

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(8, 10); // CE, CSN

const byte address[6] = {192,168,0,255,17,48}; 
/*
Change it to avoid interference. Should be same for TX & RX
all 6 bytes should be between 0-255
 */
byte data[11];

void setup() {
  radio.begin();
  radio.openWritingPipe(address);// set writing address
  /*setting min transmission power, write 
  radio.setPALevel(RF24_PA_MAX);
  for long range application. NRF will draw more current when set to high power mode*/
  radio.setPALevel(RF24_PA_MAX); 
  radio.stopListening(); // set the tranceiver only as transmitter

  pinMode(2, INPUT); digitalWrite(2, HIGH);
  pinMode(3, INPUT); digitalWrite(3, HIGH);
  pinMode(4, INPUT); digitalWrite(4, HIGH);
  pinMode(5, INPUT); digitalWrite(5, HIGH);
  pinMode(6, INPUT); digitalWrite(6, HIGH);
  pinMode(7, INPUT); digitalWrite(7, HIGH);
  pinMode(14, INPUT);
  pinMode(15, INPUT);
}

void loop() 
{
  // joystick, divide by 4 to be within 1 byte value
  data[0] = constrain(analogRead(A2)/4, 1, 255); 
  data[1] = constrain(analogRead(A3)/4, 1, 255);
  
  //small buttons
  data[2] = digitalRead(3) + 1;
  data[3] = digitalRead(2) + 1;
  
  //big buttons
  data[4] = digitalRead(4) + 1;
  data[5] = digitalRead(7) + 1;
  data[6] = digitalRead(5) + 1;
  data[7] = digitalRead(6) + 1;
  
  //push switches
  data[8] = digitalRead(14) + 1;
  data[9] = digitalRead(15) + 1;

  data[10] = constrain(analogRead(A5)/4, 1, 255);
  
  radio.write(&data, sizeof(data));
  delay(5);
}
