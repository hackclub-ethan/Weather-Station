#include "DHT.h"
#include <DIYables_LCD_I2C.h>

#define DHT11_PIN 2

DHT dht11(DHT11_PIN, DHT11);
DIYables_LCD_I2C lcd(0x27, 16, 2);

void setup() {
    pinMode(2, INPUT);
    pinMode(A3, INPUT);
    pinMode(12, INPUT);
    pinMode(13, INPUT);
    pinMode(A0, INPUT);

    Serial.begin(9600);

    dht11.begin();

    lcd.init();
    lcd.backlight();
}

void loop() {
    // Temp Sensor
    float tempSenVal = analogRead(A0);
    float voltage = (tempSenVal * 5000) / 1024;
    float celcius = voltage/10;


    // Humitity Sesnor
    float humitity = dht11.readHumidity();

    // Get water level number
    float levelSen = analogRead(A3);
    float level = 10; // Need to calculate. Once I have the kit I can do testing/adjusting 

    // Set values on LCD
    lcd.clear();

    lcd.print("T: ");
    lcd.print(celcius);
    lcd.print("C ");

    lcd.print("H: ");
    lcd.print(humitity);

    lcd.setCursor(0, 1);

    lcd.print("Water: ");
    lcd.print(level);
    

    delay(60000); // One minute
}