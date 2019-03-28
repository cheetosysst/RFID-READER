#include <SPI.h>
#include <MFRC522.h>     // 引用程式庫
#include <LiquidCrystal_I2C.h>
#include <Wire.h>  // Arduino IDE 內建
//#include <Keyboard.h>
#define RST_PIN      A0        // 讀卡機的重置腳位
#define SS_PIN       10        // 晶片選擇腳位

MFRC522 mfrc522(SS_PIN, RST_PIN);  // 建立MFRC522物件
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // 設定 LCD I2C 位址

void lcdinit() {
  
  lcd.begin(16,2);
  lcd.backlight();
  lcd.write("CKCSC Checker");
  lcd.setCursor(0,1);
  lcd.write("Beta 0.1.1_2");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.write("Ready!");
}


void setup() {
  Serial.begin(115200);
  lcdinit();
  SPI.begin();
  mfrc522.PCD_Init();   // 初始化MFRC522讀卡機模組
  tone(2,600,300);
  //Keyboard.begin()
}

void loop() {
    // 確認是否有新卡片
    if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
      byte *id = mfrc522.uid.uidByte;   // 取得卡片的UID
      byte idSize = mfrc522.uid.size;   // 取得UID的長度

      for (byte i = 0; i < idSize; i++) Serial.print(id[i],HEX);
      
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("TYPE:");
      lcd.print(mfrc522.PICC_GetTypeName(mfrc522.PICC_GetType(mfrc522.uid.sak)));
      lcd.setCursor(0,1);
      lcd.write("ID: ");
      tone(2,600,300);
      
      for (byte i = 0; i < idSize; i++) {  // 逐一顯示UID碼
        lcd.print(id[i],HEX);
        if (i != idSize-1) lcd.write("-");
      }
      mfrc522.PICC_HaltA();  // 讓卡片進入停止模式
    } 
}
