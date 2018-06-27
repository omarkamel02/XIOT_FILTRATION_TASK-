
const byte ledPin = 13;
const byte interruptPin = 2;
volatile byte state = LOW;
long lastDebounceTime=0;
long debounceDelay=50;

void blink() {
  if ((millis()-lastDebounceTime)>debounceDelay)
  {
  state = !state;
  lastDebounceTime=millis();
  }
}
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, RISING);

}

void loop() {
  digitalWrite(ledPin, state);
}
