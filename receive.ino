#include <SoftwareSerial.h>;
#define RX 2 
#define TX 3 
SoftwareSerial mySerial(RX, TX);
int led = 9;
int ledd = 10;

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode (led,OUTPUT); 
  pinMode (ledd,OUTPUT); 

}

void loop() 
{

  if (mySerial.available()) 
  {

    Serial.write(mySerial.read());

    digitalWrite(led, HIGH);
    delay(500);

    digitalWrite(led, LOW);
    }
  
      else
  {
    digitalWrite(ledd, HIGH);
    delay(500);

    digitalWrite(ledd, LOW);
   }


}