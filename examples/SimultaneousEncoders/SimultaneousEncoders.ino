/**
 * @file SimultaneousEncoders.ino
 * @author Alex Casal (https://github.com/alexitoo00)
 * @brief A quick test showcasing the way to handle multiple readings from various encoders
 * @version 1.0
 * @date 2023-06-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "NewEncoder.h"

// Create two instances of the NewEncoder class
NewEncoder firstEncoder;
NewEncoder secondEncoder;

void setup()
{
    firstEncoder.begin(8, 9);    // Initialize first encoder
    secondEncoder.begin(10, 11); // Initialize second encoder

    Serial.begin(9600);
}
unsigned long delayTime = 0;
void loop()
{
    firstEncoder.Update(); // Call this functions as frequently as possible (in this case, each loop)
    secondEncoder.Update();

    if (millis() - delayTime < 200) // Optimized delay
        return;
    delayTime = millis();

    PrintData();
}

void PrintData()
{
    Serial.println("//First encoder//");
    Serial.print("Steps: \t");
    Serial.println(firstEncoder.GetSteps());
    Serial.print("Degrees: \t-\t");
    Serial.println(firstEncoder.Degrees(), 16);

    Serial.println();

    Serial.println("//Second encoder//");
    Serial.print("Steps: \t");
    Serial.println(secondEncoder.GetSteps());
    Serial.print("Degrees: \t-\t");
    Serial.println(secondEncoder.Degrees(), 16);

    Serial.println();
}