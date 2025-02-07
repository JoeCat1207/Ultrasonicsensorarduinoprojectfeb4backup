const int trigPin = 10;
const int echoPin = 9;
const int LEDpin1 = 4;
const int LEDpin2 = 2;

float duration, distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LEDpin1, OUTPUT);
  pinMode(LEDpin2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  float duration = pulseIn(echoPin, HIGH);
  float distance = (duration*.0343)/2;
  if (distance < 10){
    digitalWrite(LEDpin2, LOW);
    Serial.println ("Too close!");
    digitalWrite(LEDpin1, HIGH);
  } else if (distance > 500) {
    digitalWrite(LEDpin1, LOW);
    Serial.println ("Too far!");
    digitalWrite(LEDpin2, HIGH);
  }
  delay(100);
}