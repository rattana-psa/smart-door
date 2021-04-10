#include <LiquidCrystal.h>

LiquidCrystal lcd(22, 24, 26, 28, 30, 32);

int button = 8;
int led = 13 ;
int buz = 7;
int clr = 0;
int tme = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(3, 0);  
  lcd.print("- 73/513 -");
  
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
  Serial.begin(9600);
}

void loop() { //lcd.setCursor(0, 1); 
  boolean x = digitalRead(button);
  Serial.println(x);
  delay(100);  
  
  if(x == 0){    
    Serial.println("ON");
    lcd.setCursor(3, 0);  
    lcd.print("WELCOME :)");
    tone(buz, 1000);
    clr = 4;
    tme = 0;
  }else{
    Serial.println("OFF");
    lcd.setCursor(3, 0);  
    tone(buz, 0);
    if(clr == 4 && tme <= 50){
      lcd.print("WELCOME :)");
      tme++;
      delay(100);
      Serial.println(tme);
      if(tme == 50) clr = 3;
    }else{
      clr = 2;
      lcd.print("- 73/513 -");
    }
  }
  if(clr == 3){
    lcd.clear();
  }  
}
