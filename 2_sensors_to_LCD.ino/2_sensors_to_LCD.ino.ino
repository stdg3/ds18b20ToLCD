#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define ONE_WIRE_BUS 2
#define ONE_WIRE_BUSx 5

LiquidCrystal_I2C lcd(0x27,16,2);

OneWire oneWire(ONE_WIRE_BUS); 
OneWire oneWirex(ONE_WIRE_BUSx); 
DallasTemperature sensors(&oneWire);
DallasTemperature sensorsx(&oneWirex);

float celcius=0;
float celciusx=0;
float diff = 0;
// 4.7K resistor between  5v[RED] & singal[yellow]
void setup() {
  // put your setup code here, to run once:
  pinMode(8, OUTPUT);
  digitalWrite(8, HIGH);
  sensors.begin(); 
  lcd.init();
  lcd.backlight();
  //lcd.setCursor(0,0);
  //lcd.print("hello everyone");

}

void loop() {
  // put your main code here, to run repeatedly:
  sensors.requestTemperatures();
  sensorsx.requestTemperatures();
  celcius = sensors.getTempCByIndex(0);
  celciusx = sensorsx.getTempCByIndex(0);
  lcd.setCursor(0,0);
  lcd.print("O:");
  lcd.setCursor(2,0);
  lcd.print(celcius);
  
  lcd.setCursor(9,0);
  lcd.print("I:");
  lcd.setCursor(11,0);
  lcd.print(celciusx);
  
  diff = celcius - celciusx;
  lcd.setCursor(0,1);
  lcd.print("Fark");
  lcd.setCursor(5,1);
  lcd.print(diff);
  delay(1000);
}
