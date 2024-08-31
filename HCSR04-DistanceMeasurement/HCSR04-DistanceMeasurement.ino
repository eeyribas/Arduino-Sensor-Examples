#define TRIG_PIN 8
#define ECHO_PIN 9

void setup() 
{
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() 
{
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long microsecond = pulseIn(ECHO_PIN, HIGH);
  long distance = microsecond / 58.3;
  Serial.print(distance);
  Serial.println(" cm");
  delay(1500);
}