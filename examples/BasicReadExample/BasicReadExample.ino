/**
 * @file BasicReadExample.ino
 * @author Alex Casal (https://github.com/alexitoo00)
 * @brief A basic example to obtain all possible properties of a rotary encoder
 * @version 1.0
 * @date 2023-06-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "NewEncoder.h"

NewEncoder encoder; // Create an instance of the class NewEncoder

void setup()
{
    // pin A or CLOCK, pin B or DATA, number of steps per turn and pin of SWITCH button
    encoder.begin(8, 9, 13, 20);
    Serial.begin(9600);
}

unsigned long delayTime = 0;
void loop()
{
    encoder.Update(); // Call this function as frequently as possible (in this case, each loop)

    if (millis() - delayTime < 200) // Optimized delay
        return;
    delayTime = millis();

    PrintData();
}

void PrintData()
{
    Serial.print("Button: \t-\t");
    Serial.println(encoder.ButtonPressed() ? "true" : "false");

    Serial.print("Steps: \t\t-\t");
    Serial.println(encoder.GetSteps());

    Serial.print("Direction: \t-\t");
    Serial.println(encoder.GetDirectionName());

    Serial.print("Percentage: \t-\t");
    Serial.println(encoder.Percentage(), 16);

    Serial.print("Percentage of turn: \t-\t");
    Serial.println(encoder.PercentageOfTurn(), 16);

    Serial.print("Radians: \t-\t");
    Serial.println(encoder.Radians(), 16);

    Serial.print("Degrees: \t-\t");
    Serial.print(encoder.Degrees(), 16);
    Serial.println("º");

    Serial.println();
}
