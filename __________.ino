int r_in;
int radius_stats;
int b1_in;
int b2_in;
int max_correct = 1023;
int min_correct = 0;
int r_pin = 0;
#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup() {
pinMode(r_pin ,INPUT);
pinMode(6 ,INPUT);
pinMode(7 ,INPUT);
 lcd.begin(16, 2);
 Serial.begin(9600);
}

void loop() {
  r_in = analogRead(r_pin);
  radius_stats = map(r_in , min_correct , max_correct , 0 , 360);
  lcd.setCursor(0, 0);
  lcd.print(radius_stats);
  Serial.println(radius_stats);
  lcd.clear();
  b1_in = digitalRead(6);
  b2_in = digitalRead(7);
  if(b1_in){
    min_correct = r_in;
  }
  Serial.println(min_correct);
  if(b2_in){
    max_correct = r_in;
  }
  Serial.println(max_correct);
  delay(500);
}
