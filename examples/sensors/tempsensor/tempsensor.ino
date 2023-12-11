#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
int ledPin = 13;
float presentTemp = 1000.0;
void setup() {
 pinMode(ledPin, OUTPUT);
 dht.begin();
 Serial.begin(9600);
}
void loop()
{
float currentTemp = dht.readTemperature();
if (isnan(currentTemp))
{
Serial.print("Current Temp: ");
Serial.println(currentTemp);
digitalWrite(ledPin, currentTemp > presentTemp);
 }
 delay(2000);
}
 
