// Pin kontrol untuk motor stepper
int IN1 = 8;
int IN2 = 9;
int IN3 = 10;
int IN4 = 11;

int stepCount = 100;     // Jumlah langkah untuk satu putaran penuh
int delaytime = 40;      // Delay antar langkah (ms)

void setup() {
  // Set pin sebagai output
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  putarMaju(stepCount / 4);         // Putar 90° searah jarum jam
  delay(1000);

  putarMundur(stepCount * 3 / 4);   // Putar 270° berlawanan arah jarum jam
  delay(1000);

  putarMaju(stepCount);             // Putar 360° searah jarum jam
  delay(1000);
}

// Putar searah jarum jam
void putarMaju(int steps) {
  for (int i = 0; i < steps; i++) {
    maju();
  }
}

// Putar berlawanan arah jarum jam
void putarMundur(int steps) {
  for (int i = 0; i < steps; i++) {
    mundur();
  }
}

// Urutan langkah maju
void maju() {
  step1(); delay(delaytime);
  step2(); delay(delaytime);
  step3(); delay(delaytime);
  step4(); delay(delaytime);
}

// Urutan langkah mundur
void mundur() {
  step4(); delay(delaytime);
  step3(); delay(delaytime);
  step2(); delay(delaytime);
  step1(); delay(delaytime);
}

// Urutan langkah stepper motor
void step1() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
}

void step2() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void step3() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void step4() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
