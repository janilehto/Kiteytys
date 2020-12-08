#define LED 3
void setup()
{
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}
#define VIIVE 20
#define DIMMED 100
#define BRIGHT 200
int kirkkaus = DIMMED;
void loop()
{
  analogWrite(LED, kirkkaus);
  delay(VIIVE);
  if( kirkkaus < BRIGHT ){
  	kirkkaus++;
  }else{
    kirkkaus = DIMMED;
  }
  Serial.println( kirkkaus );
}
