/*paring 1234*/
#include <SoftwareSerial.h>
const int rxpin = 2;
const int txpin = 3;
SoftwareSerial bluetooth(rxpin, txpin);

void setup()
{ 
  Serial.begin(9600);
  //delay(100);
  bluetooth.begin(9600);
  
  Serial.println("Serial ready");
  bluetooth.println("Bluetooth ready");
}

char c;

void loop()
{
  if(bluetooth.available())
  {
    c = bluetooth.read();
    bluetooth.write(c);
    Serial.write(c);
  }
  else if(Serial.available())
  {
    c = Serial.read();
    Serial.write(c);
    bluetooth.write(c);
  }
}
