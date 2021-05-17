#include<Servo.h>

#define TRIG 3 //TRIG 핀 설정 (초음파 보내는 핀)
#define ECHO 4 //ECHO 핀 설정 (초음파 받는 핀)

#define TRIG2 7 //TRIG 핀 설정 (초음파 보내는 핀)
#define ECHO2 8 //ECHO 핀 설정 (초음파 받는 핀)

Servo servo;

int value = 0;
long duration = 0;
long distance = 0;
long duration2 = 0;
long distance2 = 0; 
int anglepos =  100;

void setup() {
  servo.attach(5);
  Serial.begin(9600); 
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(TRIG2, OUTPUT);
  pinMode(ECHO2, INPUT); 
}

void loop() {
    
    //Trig 핀으로 10us의 pulse 발생
    digitalWrite(TRIG, LOW); 
    delayMicroseconds(2);   
    digitalWrite(TRIG, HIGH); 
    delayMicroseconds(10);            
    digitalWrite(TRIG, LOW);
    duration = pulseIn(ECHO, HIGH);
    distance = duration / 58.2;
      
    digitalWrite(TRIG2, LOW); 
    delayMicroseconds(2); 
    digitalWrite(TRIG2, HIGH); 
    delayMicroseconds(10);  
    digitalWrite(TRIG2, LOW);      
    duration2 = pulseIn(ECHO2, HIGH); 
    distance2 = duration2 / 58.2;

    Serial.println(distance);
    Serial.println(distance2); 

    follow();    
    delay(200);
}

void follow() {
  if ( distance <= 150 || distance2 <= 150 ) {
      if ( distance < 30 && distance2 > 100 )
      {
         anglepos = 0;     
      }
      else if(distance > 100 && distance2 < 30)
      {
         anglepos = 160;    
      }
      else
      {
        anglepos = 100;
      }
      servo.write(anglepos);
      delay(10);
   }
   
}
