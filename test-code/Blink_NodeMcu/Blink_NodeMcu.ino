//  Blink NodeMcu
int led_D0 = D0; // Pin D0 has an LED connected on most NodeMcu boards.
int led_D4 = D4; // Pin D4 has an LED connected on most ESP8266 boards.

void setup() {                
  // initialize the digital pin as an output.
  pinMode(led_D0, OUTPUT);     
  pinMode(led_D4, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led_D0, HIGH);   // turn the LED off 
  digitalWrite(led_D4, LOW);    // turn the LED on 
  delay(500);                   // wait for 1 second
  
  digitalWrite(led_D0, LOW);    // turn the LED on 
  delay(200);                   // wait for 0.2 second
  digitalWrite(led_D0, HIGH);   // turn the LED off 
  delay(200);                   // wait for 0.2 second
  digitalWrite(led_D0, LOW);    // turn the LED on 
  digitalWrite(led_D4, HIGH);   // turn the LED off 
  delay(200);                   // wait for 0.2 second
}
