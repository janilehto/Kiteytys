#define LED 3
void setup()
{
  pinMode(LED, OUTPUT);
}
#define VIIVE 1000
void loop()
{
  digitalWrite(LED, HIGH);
  delay(VIIVE);
  digitalWrite(LED, LOW);
  delay(VIIVE);
}
