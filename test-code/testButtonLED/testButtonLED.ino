int but = 24;
int lock = 36;

void setup() {
  pinMode(but, INPUT);
  pinMode(lock, OUTPUT);
  Serial.begin(9600);
  digitalWrite(lock, LOW);

}

void loop() {
  int a = digitalRead(but);
  Serial.println(a);
  if(a == 1){
    digitalWrite(lock, HIGH); //At this point the relay turns on  
    Serial.println("HIGH"); 
    digitalWrite(lock, LOW); //turn off the relay again  
  }
}
