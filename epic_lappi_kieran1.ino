#include <LiquidCrystal.h>

#include <Servo.h>

// define pin numbers
int trigPin = 9;
int echopin = 8;
//Create servo object to contro; a servo
Servo S6;
Servo S7;
Servo S10;
Servo S13;
Servo S14;
Servo S15;
//LED
LiquidCrystal lcd (12, 11, 5, 4, 3, 2);

void setup(){
pinMode(trigPin,OUTPUT);
pinMode(echopin,INPUT);
Serial.begin(9600);
  S7.attach(7);
  S6.attach(6);
  S10.attach(10);
  S13.attach(13);
  S14.attach(14);
  S15.attach(15);
  lcd.begin(16,2);
  
  S6.write(0); //intial pos
  S7.write(0); //intial pos
  S10.write(0); //intial pos
  S13.write(0);
  S14.write(0);
  S15.write(0);
}//end void setup

void loop(){
Serial.print("Distance: ");
Serial.print (calc_dis());
  if (calc_dis()<=10){
    S7.write(90);
    S6.write(90);
    S10.write(90);
    S13.write(90);
    S14.write(90);
    S15.write(90);
    delay (1000);
    lcd.setCursor(2,1);
    lcd.print("Hey near");
  }
  else if (calc_dis()<=50){
    delay(1000);
     S7.write(180);
    S6.write(180);
    S10.write(180);
    S13.write(180);
    S14.write(180);
    S15.write(180);
    lcd.setCursor(2,1);
    lcd.print("Hey there:) ");
  }
  else if (calc_dis()<=100){
    delay(1000);
     S7.write(0);
    S6.write(0);
    S10.write(0);
    S13.write(0);
    S14.write(0);
    S15.write(0);
    lcd.setCursor(2,1);
    lcd.print("Hey far :( ");
  }
  lcd.setCursor (0,0);
  lcd.print("distance= ");
  lcd.print (calc_dis());
  
}//end void loop

//function
int calc_dis(){
  int duratction,distance;
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duratction= pulseIn (echopin,HIGH);
  distance= duratction*0.034/2;
return distance;
}