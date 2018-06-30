
const byte ledPin = 13; 
const byte sensorpin= A1;
const byte interruptPin = 2; //the interrupt pin is 2
volatile byte state = LOW;  //determining the led state
long lastDebounceTime=0;   //last debounce time to overcome the bouncing effect
long debounceDelay=100;   //needed delay to overcome bouncing effect
long reading_rate=3000; // 3 secns rate
long last_read=0;  // to be able to count the 3 seconds

void setup() {
  pinMode(ledPin, OUTPUT);  // the led pin is output
  pinMode(interruptPin, INPUT_PULLUP); // configuring the interrupt pin as a switch input with pull up resistor
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, RISING); //make interrupt on the rising edge, calling the blink function
  Serial.begin(9600);// setting up the UART to the monitor
  

}

void loop() {
  digitalWrite(ledPin, state); // showing the led status form the last interrupt
  //sensor code , rate= 3sec
  if((millis()-last_read)>=reading_rate)//
  {
    last_read=millis();
    Serial.print(temp_read());
    Serial.print('\n');
    
  }
  
  
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
float temp_read(){
  //reading from the sensor
int  val=analogRead(sensorpin); //reading the register value from the ADC
  float mv = ( val/1024.0)*5000; //knwoing the corresponding mV to this value, max is 5000mv that corresponds to 1024
  float cel = (mv/10); //converting the mv to temprature,,, 1c=10mv
  return cel;
  }
