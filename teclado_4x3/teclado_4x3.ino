/*
 * Library taken : https://playground.arduino.cc/Code/Keypad
 * This is the Arduino code for 4x3 keypad.
 * watch the video for details and demo http://youtu.be/qIDzzG2LUtg
 *  * 
 * Modefied by Ahmad Shamshiri for Robojax Video channel www.Robojax.com
 * Date: July 11, 2018 at 19:56 in Ajax, Ontario, Canada
 * Permission granted to share this code given that this
 * note is kept with the code.
 * Disclaimer: this code is "AS IS" and for educational purpose only.
 * this code has been downloaded from http://robojax.com/learn/arduino/
 * Watch video instruction for this code: 
 * 
 */
/* @file HelloKeypad.pde
|| @version 1.0
|| @author Alexander Brevig
|| @contact alexanderbrevig@gmail.com
||
|| @description
|| | Demonstrates the simplest use of the matrix Keypad library.
|| #
*/
#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'*', '0', '#'}};

byte rowPins[ROWS] = {2, 3, 4, 5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6, 7, 8};    //connect to the column pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup()
{
    // Robojax 4x3 keypad test
    Serial.begin(9600);
    Serial.println("Robojax 4x3 keypad");
}

void loop()
{
    // Robojax 4x3 keypad test
    char key = keypad.getKey();
    // just print the pressed key
    if (key)
    {
        Serial.println(key);
    }
    // this checkes if 4 is pressed, then do something. Here  we print the text but you can control something.
    if (key == '4')
    {
        // if key matches what you are looking for
        Serial.println("Key 4 is pressed");
    }
}