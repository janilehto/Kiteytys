#define LED 3
#define POT A5
#define BUTTON 7

void setup()
{
  pinMode(LED, OUTPUT);
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

void loop()
{
  if( buttonPressed() ){
    Serial.println( "Painettu" );
  }
}








