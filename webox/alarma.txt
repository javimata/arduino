byte sensorpir = 2;
byte led       = 13;
byte buzzer    = 12;

void setup()
{
	pinMode(sensorpir, INPUT);
    pinMode(led, OUTPUT);
    pinMode(buzzer, OUTPUT);
    Serial.begin(115200);
    noTone(buzzer);
}

void loop()
{
	if ( digitalRead(sensorpir) == HIGH ) {
        Serial.println("Detectado de movimiento");
        digitalWrite(led, HIGH);
        for (size_t i = 1000; i < 4000; i++)
        {
            tone(buzzer, i);
        }
        delay(1000);
        digitalWrite(led, LOW);
        noTone(buzzer);
    }
}
