const int buzzer = 2; //Puerto de conexion del buzzer

void setup() {
    pinMode(buzzer, OUTPUT); // Set buzzer - pin indicado como salida
}

void loop() {
    tone(buzzer, 1000); // Send 1KHz sound signal...
    delay(1000);        // ...for 1 sec
    noTone(buzzer);     // Stop sound...
    delay(1000);        // ...for 1sec
}