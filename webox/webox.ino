/**
 * Proyecto WeBOX
 * Sensores:
 *      Humedad & temperatura
 *      Movimiento
 *      Luminosidad
 * 
 * Actuadores
 *      Rele (2)
 *      Buzzer
*/

int sensormov = 2;
int sensorhum = 3;
int sensorlum = 4;
int buzzer    = 9;
int rele1     = 11;
int rele2     = 12;
int led       = 13;

int FOTOPIN      = A0;
int valorSensor  = 0;

void setup(){

    pinMode(FOTOPIN, INPUT);
    pinMode(sensormov, INPUT);
    pinMode(sensorhum, INPUT);
    pinMode(sensorlum, INPUT);
    
    pinMode(rele1, OUTPUT);
    pinMode(rele2, OUTPUT);
    pinMode(led, OUTPUT);
    pinMode(buzzer, OUTPUT);
    noTone(buzzer);

    Serial.begin(115200);

}

void loop() {

    valorSensor = analogRead(FOTOPIN);

    digitalWrite(rele, LOW);
    digitalWrite(led, LOW);
    while ( digitalRead(sensormov) == HIGH ) {

        if ( valorSensor < 600 ) {
            digitalWrite(rele, HIGH);
            digitalWrite(led, HIGH);
        }
        Serial.println("Movimiento detectado");
        for (size_t i = 1000; i < 4000; i++)
        {
            tone(buzzer, i);
        }
        noTone(buzzer);
    }
    // delay(1000);

}
