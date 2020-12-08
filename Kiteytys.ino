#define LED 3
#define POT A5
#define BUTTON 7

#define LEDON HIGH
#define LEDOFF LOW

int ledState = LEDOFF;

void toggleLed(){
  if( ledState == LEDOFF ){
    ledState = LEDON;
  }else{
    ledState = LEDOFF;
  }
  digitalWrite( LED, ledState );
}

void setup()
{
  pinMode(LED, OUTPUT);
  digitalWrite(LED, ledState);
  pinMode(BUTTON, INPUT_PULLUP);
  
  Serial.begin(9600);
}

int count = 0;
bool buttonPressed(){
  int x = digitalRead( BUTTON );
  if( x == LOW ){
    count++;
  }else{
    count=0;
  }
  if( count == 1 ){
    return true;
  }
  return false;
}

unsigned long mennytHetki = 0;
#define VIIVE 200

void blink(){
  unsigned long aikaNyt = millis();
  if( ( aikaNyt - mennytHetki ) >= VIIVE ){
    mennytHetki = aikaNyt;
    toggleLed();
  }
}

bool blinkOn=false;
void toggleState(){
  if( blinkOn ){
    blinkOn = false;
  }else{
    blinkOn = true;
  }
}

void loop()
{
  if( buttonPressed() ){
    toggleState();
  }
  if( blinkOn ){
  	blink();
  }
}
