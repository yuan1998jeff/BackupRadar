int triggerPin = 6;
int echoPin1 = 11;
int echoPin2 = 12;
int echoPin3 = 13;
int durationL, cmL, inchesL, durationM, cmM, inchesM, durationR, cmR, inchesR;

int redpin = 8; // select the pin for the red LED
int bluepin = 9; // select the pin for the blue LED
int greenpin = 10 ;// select the pin for the green LED

void setup() {
  Serial.begin (9600);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(echoPin2, INPUT);

  pinMode (redpin, OUTPUT);
  pinMode (bluepin, OUTPUT);
  pinMode (greenpin, OUTPUT);
}

void loop() {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(5);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  durationL = pulseIn(echoPin1, HIGH);

  cmL = (durationL/2) / 29.1;      
  inchesL = (durationL/2) / 74;

  if (cmL < 20) {
  analogWrite (8, 255);
  analogWrite (9, 0);
  analogWrite (10, 0);
  }
  else if ((cmL > 20) && (cmL < 40)) {
  analogWrite (8, 150);
  analogWrite (9, 50);
  analogWrite (10, 0);
  }
  else if (cmL > 40) {
  analogWrite (8, 0);
  analogWrite (9, 255);
  analogWrite (10, 0);
  }

  Serial.print(inchesL);
  Serial.print(" inchesL, ");
  Serial.print(cmL);
  Serial.print(" cmL");
  Serial.println();

  delay(200);
  
/*  digitalWrite(triggerPin, LOW);
  delayMicroseconds(5);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  durationM = pulseIn(echoPin2, HIGH);

  cmM = (durationM/2) / 29.1;      
  inchesM = (durationM/2) / 74;

  Serial.print(inchesM);
  Serial.print(" inchesM, ");
  Serial.print(cmM);
  Serial.print(" cmM");
  Serial.println();
  delay(1000);

  digitalWrite(triggerPin, LOW);
  delayMicroseconds(5);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  durationR = pulseIn(echoPin3, HIGH);

  cmR = (durationR/2) / 29.1;      
  inchesR = (durationR/2) / 74;

  Serial.print(inchesR);
  Serial.print(" inchesR, ");
  Serial.print(cmR);
  Serial.print(" cmR");
  Serial.println();
  delay(1000);
  */

}
