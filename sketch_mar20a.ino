#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>  // Arduino IDE built in
//#include <Keyboard.h>
#define RST_PIN      A0        // Reader pin
#define SS_PIN       10

MFRC522 mfrc522(SS_PIN, RST_PIN);  // 建立MFRC522物件
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // LCD I2C address

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
  mfrc522.PCD_Init();   // init mfrc522
  tone(2,600,300);
  //Keyboard.begin()
}

void loop() {
    // check if there is a new card
    if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
      byte *id = mfrc522.uid.uidByte;   // get UID
      byte idSize = mfrc522.uid.size;   // get UID length

      for (byte i = 0; i < idSize; i++) Serial.print(id[i],HEX); // send to serial port
      
      // Print on lcd
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("TYPE:");
      lcd.print(mfrc522.PICC_GetTypeName(mfrc522.PICC_GetType(mfrc522.uid.sak)));
      lcd.setCursor(0,1);
      lcd.write("ID: ");
      tone(2,600,300);
      
      for (byte i = 0; i < idSize; i++) {  // show 
        lcd.print(id[i],HEX);
        if (i != idSize-1) lcd.write("-");
      }
      
      
      mfrc522.PICC_HaltA();  // stop the reader
    } 
}
