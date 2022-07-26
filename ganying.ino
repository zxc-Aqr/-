#include<Servo.h>
#define DuoPIN D5
#define Echo D2
#define Trig D8

Servo myDuoJi;
long getTime()
{
     digitalWrite(Trig, HIGH);
     delayMicroseconds(10);
     digitalWrite(Trig,LOW);
     
     return pulseIn(Echo,HIGH);
}

void initCSB()
{
   pinMode(Echo, INPUT);
   pinMode(Trig, OUTPUT);
}

void setup(){
    initCSB();
   myDuoJi.attach(DuoPIN);
    Serial.begin(115200);
}

void loop(){
    long dis;
    dis = getTime()/58;

  
    if(dis <10){
         myDuoJi.write(45);//用于调节舵机转的角度
      delay(2000);
   }else{
        myDuoJi.write(270);//用于调节舵机转的角度
     }
  
}
