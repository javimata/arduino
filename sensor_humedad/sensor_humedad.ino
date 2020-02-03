#include <DHT.h>

int SENSOR = 2;
int temp, humedad;

DHT dht (SENSOR, DHT11);

void setup(){
    Serial.begin(9600);
    dht.begin();
}

void loop(){
    humedad = dht.readHumidity();
    temp    = dht.readTemperature();

    Serial.print("Temperatura: ");
    Serial.print(temp);
    Serial.print("ºC Humedad: ");
    Serial.print(humedad);
    Serial.println("%");

    delay(500);

}