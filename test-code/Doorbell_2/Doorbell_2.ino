int button = 8;
int led = 13;
int buz = A0;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
  Serial.begin(9600);

}
void loop() {  
  boolean x = digitalRead(button);
  Serial.println(x);
  
  if(x == 1){
    Serial.println("ON");
    tone(buz, 1000);
  }else{
    Serial.println("OFF");
    tone(buz, 0);
  }

}
