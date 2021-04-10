int button = 24;
int led = 13 ;
int buzz = 3;

void setup(){ 
  pinMode(led, OUTPUT); 
  pinMode(button, INPUT_PULLUP); // set the internal pull up resistor, unpressed button is HIGH 
  Serial.begin(9600);
}

void loop(){ 
  if (digitalRead(button) == true) { 
    digitalWrite(led, HIGH); 
    Serial.println("On");
    tone(buzz, 1000);
      delay(200);
      tone(buzz, 500);
      delay(500);
    //while(digitalRead(button) == true);
  }else{
    digitalWrite(led, LOW); 
    Serial.println("OFF");
   // while(digitalRead(button) == false)
      tone(buzz, 0);
  }  
  delay(50); // keeps a small delay 
}
