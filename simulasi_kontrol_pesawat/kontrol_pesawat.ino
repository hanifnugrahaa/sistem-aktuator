#include <Servo.h>

// Deklarasi untuk motor servo
Servo aileronServo; // Servo untuk aileron (sayap)
Servo rudderServo;  // Servo untuk rudder (ekor)

// Pin motor BLDC dan potensiometer
const int bldcPin = 9;     // Pin untuk sinyal ESC motor BLDC
const int potPin = A0;     // Pin potensiometer

// Variabel untuk kontrol servo
const int servoMin = 0;    // Sudut minimum servo
const int servoMax = 180;  // Sudut maksimum servo
unsigned long prevTime = 0; 
const int period = 2000;   // Periode gerakan servo (2 detik)

// Variabel status servo
bool movingUp = true;      // Status gerakan servo naik/turun

void setup() {
  // Konfigurasi servo
  aileronServo.attach(6);  // Hubungkan servo aileron ke pin 6
  rudderServo.attach(7);   // Hubungkan servo rudder ke pin 7

  // Set posisi awal servo
  aileronServo.write(90);  // Posisi tengah
  rudderServo.write(90);   // Posisi tengah

  // Konfigurasi BLDC motor
  pinMode(bldcPin, OUTPUT);
  analogWrite(bldcPin, 0); // Mulai dengan kecepatan 0
}

void loop() {
  // Baca nilai potensiometer
  int potValue = analogRead(potPin);
  int motorSpeed = map(potValue, 0, 1023, 0, 255);
  analogWrite(bldcPin, motorSpeed);

  // Kontrol servo secara periodik
  unsigned long currentTime = millis();
  if (currentTime - prevTime >= period) {
    prevTime = currentTime;

    if (movingUp) {
      aileronServo.write(servoMax);
      rudderServo.write(servoMax);
    } else {
      aileronServo.write(servoMin);
      rudderServo.write(servoMin);
    }
    movingUp = !movingUp; // Ubah arah gerakan
  }
}
