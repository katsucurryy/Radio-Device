#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 10); // CE, CSN



const byte addresses[][6] = {"00001", "00002", "00003"};

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(addresses[2]); // 00003
  radio.openReadingPipe(1, addresses[1]);// 00002
  radio.setPALevel(RF24_PA_MIN);
}
void loop() { 

  radio.startListening();
  
  if (radio.available()) {
    
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.println(text);
    if (sizeof(text)>1){
    radio.stopListening();
   
    radio.write(&text, sizeof(text));
    
   radio.startListening();
      
    }
    
  
  
  
}}
