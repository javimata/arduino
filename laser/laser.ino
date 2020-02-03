int LASER = 9;

void setup()
{
    pinMode(LASER, OUTPUT);
    digitalWrite(LASER, LOW);
}

void loop()
{

    digitalWrite(LASER, HIGH);
    delay(5000);
    digitalWrite(LASER, LOW);
    delay(500);
}