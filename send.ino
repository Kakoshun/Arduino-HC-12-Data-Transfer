
#include <SoftwareSerial.h>;
#define RX 2 
#define TX 3 

SoftwareSerial hc12(RX, TX); 

const int tr = 9; 
const int ec = 8; 
long cm_dist;

void setup() {

  
  hc12.begin(9600); 
  pinMode(tr, OUTPUT);
  pinMode(ec, INPUT);
}


long microsecondsToCentimeters(long microseconds)
{
return microseconds / 58;
}
long Read_Distance()
{
long duration,cm;
digitalWrite(tr, LOW);
delayMicroseconds(2);
digitalWrite(tr, HIGH);
delayMicroseconds(10);
digitalWrite(tr, LOW);
duration = pulseIn(ec, HIGH,30000);
if (duration==0)
{
pinMode(ec, OUTPUT);
delay(10);
digitalWrite(ec, LOW);
delay(10);
pinMode(ec, INPUT);
delay(10);
}
cm = microsecondsToCentimeters(duration);
return cm;
}

void loop() 

{ 

cm_dist=Read_Distance();


    if (cm_dist<100) 
    {
      hc12.print(cm_dist,2); 
      delay(1000);
    }
    
}