#define trig 10
#define echo 9
int duration;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

float sonar_activate()
{
  delay(10);
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(5);

  duration = pulseIn(echo,HIGH);
  float distance=(duration*.035)/2;
  Serial.println(distance);
  return distance;
  }
   
void loop() {
  // put your main code here, to run repeatedly:
sonar_activate();
}
