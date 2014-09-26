#include <SoftwareSerial.h>

int pulsePin = 0;                 
const int rxpin = 2;
const int txpin = 3;
SoftwareSerial bluetooth(rxpin, txpin);

volatile int BPM;                 
volatile int Signal;              
volatile int IBI = 600;           
volatile boolean Pulse = false;   
volatile boolean QS = false;      


void setup(){
  bluetooth.begin(9600);          
  interruptSetup();               
}



void loop(){
  if (QS == true){
        bluetooth.print('B');
        bluetooth.println(BPM);
        QS = false;
     }
  delay(20);
}
