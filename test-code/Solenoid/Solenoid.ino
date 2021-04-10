#define lock D0

void setup()
{
  pinMode(lock, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(lock, HIGH); //At this point the relay turns on  
  Serial.println("HIGH");
  delay(3000); //..wait one second  
  digitalWrite(lock, LOW); //turn off the relay again  
  Serial.println("LOW");
  delay(3000); //…wait a second
}
