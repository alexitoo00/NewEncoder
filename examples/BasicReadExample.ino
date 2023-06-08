#include "NewEncoder.h"

NewEncoder encoder(8, 9, 20, 13);;

void setup()
{
    // encoder.setup(8, 9, 20, 13);
    Serial.begin(9600);
}
unsigned long delayTime = 0;
void loop()
{
    encoder.Update(); // Call this function as frequently as possible (in this case, each loop)

    if (millis() - delayTime < 200) // Optimized delay
        return;
    delayTime = millis();

    Serial.print("Button: \t-\t");
    Serial.println(encoder.ButtonPressed() ? "true" : "false");

    Serial.print("Steps: \t\t-\t");
    Serial.println(encoder.GetSteps());

    Serial.print("Direction: \t-\t");
    switch (encoder.GetDirection())
    {
    case 0:
        Serial.println("None");
        break;
    case 1:
        Serial.println("Clockwise");
        break;
    case 2:
        Serial.println("Counterclockwise");
        break;
    }

    Serial.print("Percentage: \t-\t");
    Serial.println(encoder.Percentage(), 16);

    Serial.print("Percentage of turn: \t-\t");
    Serial.println(encoder.PercentageOfTurn(), 16);

    Serial.print("Radians: \t-\t");
    Serial.println(encoder.Radians(), 16);

    Serial.print("Degrees: \t-\t");
    Serial.println(encoder.Degrees(), 16);

    Serial.println();
}
