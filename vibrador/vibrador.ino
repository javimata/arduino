int SENSOR = 2;

void setup()
{
	pinMode(SENSOR, OUTPUT);
}

void loop()
{
	digitalWrite(SENSOR, HIGH);
    delay(500);
    digitalWrite(SENSOR, LOW);
    delay(500);
}
