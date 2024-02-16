#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 10); // CE, CSN




const byte addresses[][6] = {"00001", "00002"};
void setup() {
  Serial.begin(9600);
  radio.begin();
 radio.openWritingPipe(addresses[1]); // 00002
  radio.openReadingPipe(1, addresses[0]); // 00001
  radio.setPALevel(RF24_PA_MIN);
}
void loop() {
  delay(500);
  const char text[] = "test";
  radio.stopListening();
radio.write(&text, sizeof(text));
/*
delay(10);
radio.startListening();
if (radio.available()){
 while (!radio.available());
 if (sizeof(text)>1){
 radio.read(&text, sizeof(text));
 Serial.println(text); 
  
}}*/
}
