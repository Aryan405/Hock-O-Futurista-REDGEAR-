#include <IRremote.h>

IRrecv IR(12);
decode_results myresult;

#define echopin1 2
#define echopin2 3
#define echopin3 4
#define echopin1 2
#define echopin2 3
#define echopin3 4
#define triggpin1 5
#define triggpin2 6
#define triggpin3 7
#define buzzer 8
#define motor 9
#define led1 10
#define ldr A0
#define led2 A2
#define led3 A1

long duration1 , distance1 , duration2 , distance2 , duration3 , distance3 ;
unsigned int ldr_data;
const int ldr_value = 400;
void setup()
{
  IR.enableIRIn();
  //Serial.begin(9600);
  pinMode(echopin1 , INPUT);
  pinMode(echopin2 , INPUT);
  pinMode(echopin3 , INPUT);
  pinMode(led3 , OUTPUT);
  pinMode(led2 , OUTPUT);
  for(int i=5; i<=10; i++)
  {
  pinMode(i , OUTPUT);
  }
}

void loop()
{
   ldr_data = analogRead(ldr);
  if(ldr_data <= ldr_value)
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
    tone(buzzer , 1500 , 800);
    digitalWrite(motor , HIGH);
    delay(500);
    digitalWrite(motor , LOW);
    delay(500);
  }

  digitalWrite(triggpin2 , LOW);
  delayMicroseconds(2);
  digitalWrite(triggpin2 ,HIGH);
  delayMicroseconds(10);
  digitalWrite(triggpin2 , LOW);
  
  duration2 = pulseIn(echopin2 , HIGH);
  distance2 = duration2 * 0.034/2;
  
  if(distance2<100)
  {
    tone(buzzer , 2500 , 600);
    digitalWrite(motor , HIGH);
    delay(100);
    digitalWrite(motor , LOW);
    delay(100);
  }


  digitalWrite(triggpin3 , LOW);
  delayMicroseconds(2);
  digitalWrite(triggpin3 , HIGH);
  delayMicroseconds(10);
  digitalWrite(triggpin3 , LOW);
  
  duration3 = pulseIn(echopin3 , HIGH);
  distance3 = duration3 * 0.0345/2;
  
  if(distance3<100)
  {
    tone(buzzer , 500 , 500);
    digitalWrite(motor , HIGH);
    delay(100);
    digitalWrite(motor , LOW);
    delay(100);
  }
  
 if(IR.decode(&myresult))
  {
   //Serial.println(myresult.value , HEX);
 IR.resume();
 }
 // delay(100);
  
  if(myresult.value == 0xFD00FF)
 {
   digitalWrite(buzzer , HIGH);
    delay(1500);
    digitalWrite(buzzer , LOW);
    delay(100);
  }
  else if(myresult.value == 0xFD807F)
  {
    digitalWrite(buzzer , LOW);
    delay(500);
  }
  
}
