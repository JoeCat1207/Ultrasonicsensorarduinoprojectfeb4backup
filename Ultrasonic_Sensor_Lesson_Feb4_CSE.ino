const int trigPin = 10;
const int echoPin = 9;
const int LEDpinRed = 2;
const int LEDpinGreen = 4;
const int LEDpinYellow = 6;

float duration, distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LEDpinRed, OUTPUT);
  pinMode(LEDpinGreen, OUTPUT);
  pinMode(LEDpinYellow, OUTPUT);
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
  Serial.println(distance);
  if (distance <= 10){
    digitalWrite(LEDpinYellow, HIGH);
    digitalWrite(LEDpinRed, LOW);
    digitalWrite(LEDpinGreen, LOW);
  } else if (distance > 10){
      digitalWrite(LEDpinGreen, HIGH);
      digitalWrite(LEDpinRed, LOW);
      digitalWrite(LEDpinYellow, LOW);
  }
    else if (distance > 5){
      digitalWrite(LEDpinYellow, HIGH);
      digitalWrite(LEDpinRed, LOW);
      digitalWrite(LEDpinGreen, LOW);
    } if (distance < 5){
      digitalWrite(LEDpinYellow, LOW);
      digitalWrite(LEDpinRed, HIGH);
      digitalWrite(LEDpinGreen, LOW);
    }
  delay(100);
}