/*variables*/
int pulsePin = 0;                 // Pulse Sensor purple wire connected to analog pin 0

// these variables are volatile because they are used during the interrupt service routine!
volatile int BPM;                   // used to hold the pulse rate
volatile int Signal;                // holds the incoming raw data
volatile int IBI = 600;             // holds the time between beats, must be seeded! 
volatile boolean Pulse = false;     // true when pulse wave is high, false when it's low
volatile boolean QS = false;        // becomes true when Arduoino finds a beat. 


void setup(){
  Serial.begin(19200);          
  interruptSetup();                 // sets up to read Pulse Sensor signal every 2mS                
}



void loop(){
  Serial.print(QS);//QS = 심장박동이 감지되었는가
  QS = false;//reset.
  delay(20);//delay for update(interrupt updates variables)
}
