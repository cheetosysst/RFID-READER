# RFID READER

This is a arduino based RFID reader. Nothing special, it still need a lot of improvement.

The project is for the Cheng Kong Computer Science Club.

---
## Component
- Arduino UNO R3 (or any board with enough pin and is compatible with the Arduino IDE)
- I2C 16*2 LCD
- RFID-RC522
- Buzzer (optional)
---
## Wiring
I tried to create a schematic, but most service I found does not include a I2C lCD, so you'll have to bear with my poor documented wiring method.

#### LCD
-- GND - GND  
-- VCC - 5V  
-- SDA - A4  
-- SCL - A5  

#### RFID-RC522
-- 3.3v - 3.3v  
-- RST - A0  
-- GND - GND  
-- IRQ - (none)  
-- MISO - D12  
-- MOSI - D11  
-- SCK - D13  
-- SDA - D10  

#### Buzzer
-- Red - D3  
-- Black - GND  

---
## Installing
You don't, run the included main.py with
``python3 main.py ``

## Port
The project is made on a linux machine, so you'll have to make which port your using if you're running it on a Mac or Windows machine.

Actually I lied, you have make sure you're Arduino is connected to ``/dev/ttyACM0``, or you'll have to change it manually in the `` main.py`` file.

---
## Future Update

- Show all avalible ports on start
- Improve speed somehow (probably won't happen)
- UI and sample database for it (maybe another repo)
- A cute startup sound
- Bug and instablity, you know what I meant, haha...
---
## License
The project is released with MIT license, though I have no idea why you need this project to work on yours.
