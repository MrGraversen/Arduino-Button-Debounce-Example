int switchPin = 8;
int ledPin = 11;
boolean lastButton = LOW;
boolean currentButton = LOW;
int ledLevel = 0;
int testLedPin = 13;

void setup() 
{
  pinMode(switchPin, INPUT);
  pinMode(testLedPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

boolean debounce(boolean last)
{
  boolean current = digitalRead(switchPin);
  
  if(last != current)
  {
    delay(5);
    current = digitalRead(switchPin);
  }
    
  return current;
}

void loop() 
{  
  currentButton = debounce(switchPin);
  
  if(lastButton == LOW && currentButton == HIGH)
  {
    ledLevel = ledLevel + 51;
  }
  
  lastButton = currentButton;
  
  if(ledLevel > 255)
  {
    ledLevel = 0;
  }
  
  if(ledLevel  == 0)
  {
    digitalWrite(testLedPin, HIGH); 
  }
  else
  {
    digitalWrite(testLedPin, LOW); 
  }
  
  analogWrite(ledPin, ledLevel);
}
