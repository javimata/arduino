int pin = 11;
int pin2 = 12;

void setup()
{
	pinMode(pin, OUTPUT);
    pinMode(pin2, OUTPUT);
}

void loop()
{
	digitalWrite(pin, HIGH);
    delay(1000);
    digitalWrite(pin, LOW);
    delay(1000);
    digitalWrite(pin2, HIGH);
    delay(1000);
    digitalWrite(pin2, LOW);
    delay(1000);
}
