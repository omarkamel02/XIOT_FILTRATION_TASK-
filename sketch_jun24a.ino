
const byte ledPin = 13; 
const byte interruptPin = 2; //the interrupt pin is 2
volatile byte state = LOW;  //determining the led state
long lastDebounceTime=0;   //last debounce time to overcome the bouncing effect
long debounceDelay=50;   //needed delay to overcome bouncing effect


void setup() {
  pinMode(ledPin, OUTPUT);  // the led pin is output
  pinMode(interruptPin, INPUT_PULLUP); // configuring the interrupt pin as a switch input with pull up resistor
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, RISING); //make interrupt on the rising edge, calling the blink function
  Serial.begin(9600);// setting up the UART to the monitor
  

}

void loop() {
  digitalWrite(ledPin, state);
  //sensor code
}

void blink() {
  // what happens on the interrupt
  if ((millis()-lastDebounceTime)>debounceDelay)// only responding to the switch interrupt if the debounce delay time is passed
  {
  state = !state;// inverting the led status when pressing
  lastDebounceTime=millis(); // saving the current press time to be able to overcome the bouncing delay 
  Serial.print("Pressed ");
  //printing the status of the led
  if(state==LOW) Serial.print("LED IS OFF\n");
  else Serial.print("LED IS ON\n");
  }
}
