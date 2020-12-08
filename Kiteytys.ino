#define LED 3
#define POT A5

void setup()
{
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}
#define VIIVE 20
#define MAX8BIT 255
#define MIN8BIT 0
#define MAX10BIT 1023
#define MIN10BIT 0

void dimLed( int level ){
  int x = map( level, MIN10BIT, MAX10BIT, MIN8BIT, MAX8BIT );
  analogWrite( LED, x );
}

void loop()
{
  dimLed( analogRead( POT ) );
}
