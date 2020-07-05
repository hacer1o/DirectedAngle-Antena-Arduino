int r_in;
int radius_stats;
int b1_in;
int b2_in;
int max_correct = 1023;
int min_correct = 0;
int min_pin = 8;
int max_pin = 9;
int r_pin = 0;
int user_radius;

#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup() {
pinMode(r_pin ,INPUT);
pinMode(min_pin ,INPUT);
pinMode(max_pin ,INPUT);
pinMode(10 , OUTPUT);
pinMode(11 , OUTPUT);
 lcd.begin(16, 2);
 Serial.begin(9600);
}

void loop() {
 for(int i = 0; i <= 500; i++){
  r_in = analogRead(r_pin);
  radius_stats = map(r_in , min_correct , max_correct , 0 , 359);
  lcd.setCursor(0, 0);
  lcd.print(radius_stats);
  lcd.setCursor(0, 1);
  lcd.print(user_stats);
  Serial.println(radius_stats);
  lcd.clear();
  b1_in = digitalRead(min_pin);
  b2_in = digitalRead(max_pin);
  if(b1_in){
    min_correct = r_in;
  }
  Serial.println(min_correct);
  if(b2_in){
    max_correct = r_in;
  }
  Serial.println(max_correct);
  delay(1);
 user_radius = analogRead(1);
 user_radius = map(user_radius , 0 , 1023 , 0 , 359);
 if (user_radius > radius_stats){
 digitalWrite(10 , 1);
 }
 if (user_radius == radius_stats){
 digitalWrite(10 , 0);
 digitalWrite(11 , 0);
 }
 if (user_radius < radius_stats){
 digitalWrite(11 , 1);
 }
 }
}
