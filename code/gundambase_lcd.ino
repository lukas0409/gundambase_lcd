/*
  건담 격납고 윗부분에 사용되는 LCD 코드

  - 자세한 설명은 동봉된 한글 파일 참조
*/

#include <LiquidCrystal_I2C.h> // I2C LCD 라이브러리
#include <Wire.h> // LCD 2004 12C

LiquidCrystal_I2C lcd (0x27,20,4); // 접근주소: 0x3F or 0x27

// 버튼 2개 변수
int readValue7 = 0;
int readValue8 = 0;

void setup() {
  // pinMode 설정
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

// 문 열림 표출 함수
void door_openning() {
  lcd.init();
  lcd.setCursor (0, 0); // 두번째 줄 문자열 출력
  lcd.print ("Openning.......");
  delay(5000);
  readValue8 = 0;
}

// 문 닫힘 표출 함수
void door_closing() {
  lcd.init();
  lcd.setCursor (0, 0); // 두번째 줄 문자열 출력
  lcd.print ("Closing...... ");
  delay(5000);
  readValue7 = 0;
}

// 버튼 상태확인 후 함수연계
void button_check() {
  // 버튼값 동기화
  readValue7 = digitalRead(7);
  readValue8 = digitalRead(9);

  // 문 열림문구 실행 버튼 인식
  if (readValue8 == 1) {
    door_openning();
  }

  // 문 닫힘문구 실행 버튼 인식
  if (readValue7 == 1) {
    door_closing();
  }
}
