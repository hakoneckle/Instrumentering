#include <SoftwareSerial.h>

double temp;
int tempPin = 0;
char c;
bool b;
int l = 2;
int h = 30;

void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT); // red
  pinMode(12,OUTPUT); // green
  pinMode(8, OUTPUT); // buzzer
  Serial.begin(9600);
}

void loop() {
  
  if (Serial.available()){
    c = Serial.read();
    
    if (c == 'T') {
      b = true;
      while (b){
        delay(1000);
        c = Serial.read();
        if (c == 'S'){
          Serial.print("End - ");
          b = false;}
        temp = analogRead(tempPin);
        temp = ((((temp/1024) * 5)-0.5)*100);
        Serial.print("Temp = ");
        Serial.print(temp);
        Serial.print("*C , ");
        if (temp > h){
          digitalWrite(13,HIGH);
          digitalWrite(12,LOW);
          Serial.println("TOO HIGH");
        }
        else if (temp < l){
          digitalWrite(13,HIGH);
          digitalWrite(12,LOW);
          Serial.println("TOO LOW");
        }
        else{
          digitalWrite(12,HIGH);
          digitalWrite(13,LOW);
          Serial.println("PERFECT");
        }
        if (!b){
          digitalWrite(13,LOW);
          digitalWrite(12,LOW);}
      }
     }
     
     if (c == 'A') {
      b = true;
      while (b){
        delay(1000);
        c = Serial.read();
        if (c == 'S'){
          Serial.print("End - ");
          b = false;}
        temp = analogRead(tempPin);
        temp = ((((temp/1024) * 5)-0.5)*100);
        Serial.print("Temp = ");
        Serial.print(temp);
        Serial.print("*C , ");
        if (temp > h){
          digitalWrite(13,HIGH);
          digitalWrite(8,HIGH);
          digitalWrite(12,LOW);
          Serial.println("TOO HIGH");
        }
        else if (temp < l){
          digitalWrite(13,HIGH);
          digitalWrite(12,LOW);
          digitalWrite(8,HIGH);
          Serial.println("TOO LOW");
        }
        else{
          digitalWrite(12,HIGH);
          digitalWrite(13,LOW);
          digitalWrite(8,LOW);
          Serial.println("PERFECT");
        }
        if (!b){
          digitalWrite(13,LOW);
          digitalWrite(12,LOW);
          digitalWrite(8, LOW);}
      }
    }

    if (c == 'L') {
        Serial.println("Give lowest temperature as int: ");
        while (Serial.available() == 0){}
        l = Serial.parseInt();
    }
    if (c == 'H') {
        Serial.println("Give highest temperature as int: ");
        while (Serial.available() == 0){}
        h = Serial.parseInt();
    }
    
    }
 
  delay(1000);  
}
