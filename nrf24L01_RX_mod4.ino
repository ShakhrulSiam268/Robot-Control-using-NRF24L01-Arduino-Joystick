
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(8, 10); // CE, CSN; you can change these 2 pins if needed

const byte address[6] = {192,168,0,255,17,48}; 

byte data[11]; // this is where controller data is saved.

const int stepPin1 = 2; // define pin for step
const int dirPin1 = 3;  // define pin for direction

const int stepPin2 = 4; // define pin for step
const int dirPin2 = 5;  // define pin for direction

int temp=0;
int dly;

void setup() {
  Serial.begin(115200);
  radio.begin();
  radio.openReadingPipe(0, address); // set reading address
  radio.setPALevel(RF24_PA_MIN);// set min receiving power
  radio.startListening(); // set the tranceiver only as receiver

  pinMode(stepPin1,OUTPUT); 
  pinMode(dirPin1,OUTPUT);
  pinMode(stepPin2,OUTPUT); 
  pinMode(dirPin2,OUTPUT);
}

void loop() {
  if (radio.available()) 
  {
    radio.read(&data, sizeof(data));

    if (data[0] <= 60){
      if (data[1] >= 190) {Serial.println(" Left Forward ");temp=1;}
      else if (data[1] > 60 and data[1] < 190) {Serial.println(" Left ");temp=2;}
      else if (data[1] <= 60) {Serial.println(" Left Back ");temp=3;}
    }
    
    else if (data[0] > 60 and data[0] < 190){
      if (data[1] >= 190) {Serial.println(" Forward ");temp=7;}
      else if (data[1] > 60 and data[1] < 190) {Serial.println(" ---Null--- ");temp=0;}
      else if (data[1] <= 60) {Serial.println(" Back ");temp=8;}
    }
    
    else if (data[0] >= 190){
      if (data[1] >= 190) {Serial.println(" Right Forward ");temp=4;}
      else if (data[1] > 60 and data[1] < 190) {Serial.println(" Right ");temp=5;}
      else if (data[1] <= 60) {Serial.println(" Right Back ");temp=6;}
    }

    /*
    if (data[1]>190) {Serial.println(" Forward ");temp=1;}
    else if (data[1]<60) {Serial.println(" Back "); temp=2;}

    if (data[0]>190) {Serial.println(" Right ");temp=3;}
    else if (data[0]<60) {Serial.println(" Left ");temp=4;}
    
    if (data[0]<190 and data[0]>60 and data[1]<190 and data[1]>60) {Serial.println(" ----NULL------ "); temp=0;}
    */

    
    dly=map(data[10], 1, 255, 3000, 200);
    
  }

 
 if (temp==0) {digitalWrite(dirPin1, LOW);digitalWrite(dirPin2, LOW);}
 
 else if (temp==1 ) {digitalWrite(dirPin1, LOW);digitalWrite(dirPin2, LOW);}
 else if (temp==2 ) {digitalWrite(dirPin1, LOW);digitalWrite(dirPin2, LOW);}
 else if (temp==3 ) {digitalWrite(dirPin1, LOW);digitalWrite(dirPin2, HIGH);}
 
 else if (temp==4) {digitalWrite(dirPin1, HIGH);digitalWrite(dirPin2, HIGH);}
 else if (temp==5) {digitalWrite(dirPin1, LOW);digitalWrite(dirPin2, LOW);}
 else if (temp==6) {digitalWrite(dirPin1, LOW);digitalWrite(dirPin2, HIGH);}
 
 else if (temp==7) {digitalWrite(dirPin1, HIGH);digitalWrite(dirPin2, LOW);}
 else if (temp==8) {digitalWrite(dirPin1, LOW);digitalWrite(dirPin2, HIGH);}


 if (temp==0 ) {digitalWrite(stepPin1, LOW);digitalWrite(stepPin2, LOW);}
 
 else if (temp==1 ) {digitalWrite(stepPin1, LOW);digitalWrite(stepPin2, HIGH);}
 else if (temp==2 ) {digitalWrite(stepPin1, HIGH);digitalWrite(stepPin2, HIGH);}
 else if (temp==3 ) {digitalWrite(stepPin1, LOW);digitalWrite(stepPin2, HIGH);}
 
 else if (temp==4) {digitalWrite(stepPin1, HIGH);digitalWrite(stepPin2, LOW);}
 else if (temp==5) {digitalWrite(stepPin1, HIGH);digitalWrite(stepPin2, HIGH);}
 else if (temp==6) {digitalWrite(stepPin1, HIGH);digitalWrite(stepPin2, LOW);}
 
 else if (temp==7) {digitalWrite(stepPin1, HIGH);digitalWrite(stepPin2, HIGH);}
 else if (temp==8) {digitalWrite(stepPin1, HIGH);digitalWrite(stepPin2, HIGH);}
 
 delayMicroseconds(dly);
  
 digitalWrite(stepPin1, LOW);
 digitalWrite(stepPin2, LOW);
 
 delayMicroseconds(dly);
}
