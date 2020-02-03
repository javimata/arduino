//Sensor de ritmo cardiaco

//  Variables
int PulseSensor = A0; // Conecte el cable rojo del sensor en pin analogico cero
int LED13 = 13;       // Blink del LED segun la frecuencia de pulsos

int Signal = 0;
int Threshold = 520; //Dato analogico considerado como un pulso

void setup()
{
    pinMode(13, OUTPUT);
    pinMode(2, OUTPUT);
    Serial.begin(9600);
}

void loop()
{

    Signal = analogRead(PulseSensor); //Lectura de datos del sensor de ritmo cardiaco

    Serial.println(Signal);

    if (Signal > Threshold)
    {
        digitalWrite(LED13, HIGH);
    }

    if (Signal <= Threshold)
    {
        digitalWrite(LED13, LOW);
    }

}