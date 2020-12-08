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
#define UP 1
#define DOWN 0
#define STEP 10

int kirkkaus = 127;
void dimLed( int level ){
  if( level == UP ){
    if( kirkkaus < ( MAX8BIT - STEP )){
    	kirkkaus += STEP; 
    }
  }else if( level == DOWN ){
    if( kirkkaus > STEP ){
    	kirkkaus -= STEP; 
    }
  }
  analogWrite( LED, kirkkaus );
}

void loop()
{
  if( Serial.available() > 0 ){
    int x = Serial.read();
    switch (x) {
      case 'w': dimLed( UP );
      break;
      case 's': dimLed( DOWN );
      break;
    }
  }
}
