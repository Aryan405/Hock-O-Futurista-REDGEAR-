//#include <IRremote.h>

//IRrecv IR(13);
//decode_results myresult;

#define echopin1 2
#define echopin2 3
#define echopin3 4
#define triggpin1 5
#define triggpin2 6
#define triggpin3 7
#define buzzer 8
#define motor 9
#define ldr A0
#define led1 10
#define led2 11
#define led3 12

long duration1 , distance1 , duration2 , distance2 , duration3 , distance3 ;
int ldr_data;
const int threshold = 90;
void setup()
{
 
  pinMode(echopin1 , INPUT);
  pinMode(echopin2 , INPUT);
  pinMode(echopin3 , INPUT);
  
  for(int i=5; i<=12; i++)
  {
  pinMode(i , OUTPUT);
  }
  
   //IR.enableIRIn();
  //Serial.begin(9600);
}

void loop()
{
   ldr_data = analogRead(ldr);
  if(ldr_data <= threshold)
  {
    digitalWrite(led1 , HIGH);
    digitalWrite(led2 , HIGH);
    digitalWrite(led3 , HIGH);
    delay(500);
  }
  else
  {
  digitalWrite(led1 , LOW);
    digitalWrite(led2 , LOW);
    digitalWrite(led3 , LOW);
    delay(500);
  }
  
 digitalWrite(triggpin1 , LOW);
 delayMicroseconds(2);
  digitalWrite(triggpin1 ,HIGH);
  delayMicroseconds(10);
  digitalWrite(triggpin1 , LOW);
  
  duration1 = pulseIn(echopin1 , HIGH);
  distance1 = duration1 * 0.034/2;
  
  if(distance1<100)
  {
    tone(buzzer , 1500 , 1000);
    digitalWrite(motor , HIGH);
    delay(500);
    digitalWrite(motor , LOW);
    delay(500);
  }
  
 
  
}
