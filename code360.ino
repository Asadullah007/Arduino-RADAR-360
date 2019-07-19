#include <Servo.h>
#include <LiquidCrystal.h>

Servo myservo;
LiquidCrystal lcd(10, 11, 14, 15, 16, 17); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)

int pos = 0; 
const int trigPin = 8;
const int echoPin = 9;
const int moteur = 2;
const int buzzer = 6;
const int ledPin1 = 4;
const int ledPin2 = 7;
float distanceCm, DistanceSec,duration;

void setup() {
myservo.attach(moteur);
lcd.begin(16,2); 
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(buzzer, OUTPUT);
pinMode(ledPin1, OUTPUT);
pinMode(ledPin2, OUTPUT);
DistanceSec=20;

}

void loop() {
for (pos = 0; pos <= 180; pos += 10) { 
myservo.write(60); 
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH); 
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;
if (distanceCm <= DistanceSec)
{ 
  myservo.detach();
if(distanceCm <= DistanceSec/2)
{
//myservo.attach(2);

tone(buzzer, 10); // Send 1KHz sound signal...
digitalWrite(ledPin1, LOW);
digitalWrite(ledPin2, HIGH);
delay(700);
noTone(buzzer); // Stop sound...
lcd.setCursor(0,0); 
lcd.print("Distance: "); 
lcd.print(distanceCm); 
lcd.print(" cm "); 
delay(10);

lcd.setCursor(0,1);
lcd.print("Object is near");

delay(2000);

}
else
{
myservo.detach();
digitalWrite(buzzer, HIGH);
digitalWrite(ledPin2, LOW);
digitalWrite(ledPin1, HIGH);
delay(100);
digitalWrite(buzzer, LOW);
lcd.setCursor(0,0); 
lcd.print("Distance: "); 
lcd.print(distanceCm); 
lcd.print(" cm "); 
delay(10);
lcd.setCursor(0,1);
lcd.print("Object is near ");
delay(2000);

}
}
else{ myservo.attach(2);

digitalWrite(buzzer, LOW); 
digitalWrite(ledPin1, LOW);
digitalWrite(ledPin2, LOW);
myservo.detach();

}
myservo.attach(2);

lcd.setCursor(0,0); 
lcd.print("Distance: "); 
lcd.print(distanceCm);
lcd.print(" cm ");
delay(10);
  
lcd.setCursor(13,1);
lcd.print("   ");
lcd.setCursor(0,1);

lcd.print("Object is far");
delay(80);
}
for (pos = 180; pos >= 0; pos -= 10) {

myservo.write(110); //
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;
if (distanceCm <= DistanceSec){
  myservo.detach();
if(distanceCm <= DistanceSec/2)
{
tone(buzzer, 10); // Send 1KHz sound signal...
digitalWrite(ledPin1, LOW);
digitalWrite(ledPin2, HIGH);
delay(700);
noTone(buzzer); // Stop sound...
lcd.setCursor(0,0); 
lcd.print("Distance: ");
lcd.print(distanceCm); 
lcd.print(" cm "); 
delay(10);
lcd.setCursor(0,1);
lcd.print(" Object is near");
myservo.detach();
delay(2000);
}
else
{

digitalWrite(buzzer, HIGH);
digitalWrite(ledPin2, LOW);
digitalWrite(ledPin1, HIGH);
delay(100);
digitalWrite(buzzer, LOW);
lcd.setCursor(0,0); 
lcd.print("Distance: ");
lcd.print(distanceCm);
lcd.print(" cm "); 
delay(10);
lcd.setCursor(0,1);
lcd.print("Object is near");
delay(2000);
//myservo.detach();
}
}
else{myservo.attach(2);
digitalWrite(buzzer, LOW);
digitalWrite(ledPin1, LOW);
digitalWrite(ledPin2, LOW);
}

lcd.setCursor(0,0); //
lcd.print("Distance: "); //
lcd.print(distanceCm); //
lcd.print(" cm ");
delay(10);
  
lcd.setCursor(13,1);
lcd.print("   ");
lcd.setCursor(0,1);
lcd.print("Object is far");

delay(80);

}
}
