/*

*/

#include <LiquidCrystal_I2C.h>
#include <Wire.h> // LCD 2004 12C

LiquidCrystal_I2C lcd (0x27,20,4); // 접근주소: 0x3F or 0x27

int readValue7 = 0;
int readValue8 = 0;

void setup() {
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  lcd.init(); // LCD 초기화
  lcd.backlight (); // 백라이트 켜기
}

void loop() {
  button_check();

  /* 평상시 안내문구 */
  lcd.init(); // 초기화
  lcd.setCursor (0, 0); // 두번째 줄 문자열 출력
  lcd.print ("Welcome to");
  lcd.setCursor (0, 1); // 두번째 줄 문자열 출력
  lcd.print ("Give to security ID");
  delay(2000);
  button_check();

  lcd.init();
  lcd.setCursor (0, 0); // 두번째 줄 문자열 출력
  lcd.print ("Torrington Base");
  lcd.setCursor (0, 1); // 두번째 줄 문자열 출력
  lcd.print ("prove your entry status");
  delay(2000);
  button_check();

  lcd.init();
  lcd.setCursor (0, 1); // 두번째 줄 문자열 출력
  lcd.print ("status");
  delay(2000);
  button_check();

  /* AFN Thunder AM Torrington 홍보 문구 */
  lcd.init();
  lcd.setCursor (0, 0); // 두번째 줄 문자열 출력
  lcd.print ("Tune AM 1467kHz");
  lcd.setCursor (0, 1); // 두번째 줄 문자열 출력
  lcd.print ("AFN Thunder");
  delay(2000);
  button_check();

  lcd.init();
  lcd.setCursor (0, 0); // 두번째 줄 문자열 출력
  lcd.print ("and listen to");
  lcd.setCursor (0, 1); // 두번째 줄 문자열 출력
  lcd.print ("AM Torrington!");
  delay(2000);
  button_check();

  /* AFN Eagle FM Torrington 홍보 문구 */
  lcd.init();
  lcd.setCursor (0, 0); // 두번째 줄 문자열 출력
  lcd.print ("Tune FM 88.7MHz");
  lcd.setCursor (0, 1); // 두번째 줄 문자열 출력
  lcd.print ("AFN Eagle");
  delay(2000);
  button_check();

  lcd.init();
  lcd.setCursor (0, 0); // 두번째 줄 문자열 출력
  lcd.print ("and listen to");
  lcd.setCursor (0, 1); // 두번째 줄 문자열 출력
  lcd.print ("FM Torrington!");
  delay(2000);
  button_check();
}

void door_openning() {
  lcd.init();
  lcd.setCursor (0, 0); // 두번째 줄 문자열 출력
  lcd.print ("Openning.......");
  delay(5000);
  readValue8 = 0;
}

void door_closing() {
  lcd.init();
  lcd.setCursor (0, 0); // 두번째 줄 문자열 출력
  lcd.print ("Closing...... ");
  delay(5000);
  readValue7 = 0;
}

void button_check() {
  readValue7 = digitalRead(7);
  readValue8 = digitalRead(9);

  if (readValue8 == 1) {
    door_openning();
  }

  if (readValue7 == 1) {
    door_closing();
  }
}