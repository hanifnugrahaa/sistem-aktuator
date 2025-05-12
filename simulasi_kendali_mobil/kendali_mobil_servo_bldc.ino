
#include <Servo.h>
Servo ESC;
Servo setir;

const int potPin = A0;      
const int buttonPin = 2;    
const int bldcPin = 9;      

int potValue = 0;           
int servoAngle = 0;         
bool motorState = false;    
int buttonState = 0;        
int lastButtonState = 0;    

void setup(){
  ESC.attach(12,1000,2000);
  setir.attach(8);

  pinMode(potPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP); 
  pinMode(bldcPin, OUTPUT);

  setir.write(90);  
  analogWrite(bldcPin, 0);  
  Serial.begin(9600);       

}

void loop(){

  potValue = analogRead(potPin);
  servoAngle = map(potValue, 0, 1023, 0, 180); 
  setir.write(servoAngle);

  
  buttonState = digitalRead(buttonPin);
  if (buttonState == LOW && lastButtonState == HIGH) {
    motorState = !motorState; // Toggle status motor
    delay(50);               // Anti-bouncing
  }
  lastButtonState = buttonState;

  if (motorState) {
    analogWrite(bldcPin, 150); 
  } else {
    analogWrite(bldcPin, 0);
  }

  Serial.print("Servo Angle: ");
  Serial.print(servoAngle);
  Serial.print(" | Motor State: ");
  Serial.println(motorState ? "ON" : "OFF");

  delay(100);
  
  
}
