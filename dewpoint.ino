#include <DHT.h>
#include <LiquidCrystal.h>

#define DHTPIN 2 // Sensor data pin   
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);// Lcd pins

#define DHTTYPE DHT11 //Sensor type

DHT dht(DHTPIN, DHTTYPE);

float tF;
float dP;
float dPF;

void setup() {
 
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  delay(2000);

  
  if (isnan(t) || isnan(h)) {
    lcd.print("Sensor not working!");
  } else {
    
  
 lcd.print("Dew Point: ");
   lcd.print(dewPointFast(t, h));
   lcd.print(" *C ");
  dP=(dewPointFast(t, h));
  dPF=((dP*9)/5)+32;
  lcd.print(dPF);
  lcd.print(" *F");
  lcd.print(" \t");


  }
}

double dewPointFast(double celsius, double humidity)
{
 double a = 17.271;
 double b = 237.7;
 double temp = (a * celsius) / (b + celsius) + log(humidity*0.01);
 double Td = (b * temp) / (a - temp);
 return Td;
}



