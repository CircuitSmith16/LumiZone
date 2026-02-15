#include <Servo.h>

// Pin definitions
int pos;
#define TRIG_PIN 2
#define ECHO_PIN 3
#define LED_PIN 4
#define LDR_PIN A0
#define SERVO_PIN 0

#define DISTANCE_THRESHOLD 10 // cm, adjust for sitting
#define LIGHT_THRESHOLD 450   // adjust for classroom lighting
#define HOLD_TIME 5000       // 1 minute hold in milliseconds

long duration;
int distance;
int ldrValue;

Servo myServo;

// Track last time the student was detected
unsigned long lastDetectedTime = 0;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  myServo.attach(SERVO_PIN);
  myServo.write(0);
  delay(500); // Servo initial position
}

int getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2; // cm
  return distance;
}

void loop() {
  distance = getDistance();
  ldrValue = analogRead(LDR_PIN);

  Serial.print("Distance: "); Serial.print(distance); Serial.print(" cm, ");
  Serial.print("LDR: "); Serial.println(ldrValue);

  unsigned long currentTime = millis();

  // Check if student is detected
  if (distance < DISTANCE_THRESHOLD) {
    lastDetectedTime = currentTime; // reset timer
  }

  // 1️⃣ Servo control: stays ON for HOLD_TIME after last detection
  
  if (currentTime - lastDetectedTime < HOLD_TIME) {
    pos+=2; 
    myServo.write(pos);// activate servo
  } else {
    myServo.write(0);  // reset servo
  }
  

  // 2️⃣ LED control: ON if student detected AND dark
  if ((currentTime - lastDetectedTime < HOLD_TIME) && (ldrValue > LIGHT_THRESHOLD)) {
    digitalWrite(LED_PIN, HIGH); // LED ON
  } else {
    digitalWrite(LED_PIN, LOW);  // LED OFF
  }

  delay(200); // small delay for stability
}
