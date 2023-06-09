#include <Arduino.h>

class NewEncoder
{
private:
    // Pin out
    uint8_t _outA;
    uint8_t _outB;
    uint8_t _button = 0;

    // Variables
    int maxResolution = 30;
    int steps = 0;

    // States
    bool aState = false;
    bool aLastState = false;

    enum Direction
    {
        None,
        Clockwise,
        Counterclockwise
    };
    Direction DIRECTION;

public:
    void begin(uint8_t outA, uint8_t outB, uint8_t button, int resolution);
    void begin(uint8_t outA, uint8_t outB, uint8_t button);
    void begin(uint8_t outA, uint8_t outB);

    void SetResolution(int resolution);

    void Update();
    bool ButtonPressed();

    int GetSteps();
    Direction GetDirection();
    String GetDirectionName();

    float Percentage();
    float PercentageOfTurn();
    float Radians();
    float Degrees();
};

/// Constructors (various polymorphisms)
//
void NewEncoder::begin(uint8_t outA, uint8_t outB)
{
    _outA = outA;
    _outB = outB;

    pinMode(_outA, INPUT_PULLUP);
    pinMode(_outB, INPUT_PULLUP);

    DIRECTION = None;
}
void NewEncoder::begin(uint8_t outA, uint8_t outB, uint8_t button)
{
    _button = button;
    
    if (_button != 0)
        pinMode(_button, INPUT_PULLUP);

    begin(outA, outB);
}
void NewEncoder::begin(uint8_t outA, uint8_t outB, uint8_t button, int resolution)
{
    maxResolution = resolution;

    begin(outA, outB, button);
}
void NewEncoder::SetResolution(int resolution)
{
    maxResolution = resolution;
}
void NewEncoder::Update()
{
    aState = digitalRead(_outA);
    if (aState != aLastState)
    {
        if (aState != digitalRead(_outB))
        {
            steps++;
            DIRECTION = Clockwise;
        }
        else
        {
            steps--;
            DIRECTION = Counterclockwise;
        }
    }
    aLastState = aState;
}
bool NewEncoder::ButtonPressed()
{
    if (_button == 0)
        return false;
    return !digitalRead(_button);
}
int NewEncoder::GetSteps()
{
    return steps;
}
NewEncoder::Direction NewEncoder::GetDirection()
{
    return DIRECTION;
}
String NewEncoder::GetDirectionName()
{
    switch (DIRECTION)
    {
    case 0:
        return "None";
        break;
    case 1:
        return "Clockwise";
        break;
    case 2:
        return "Counterclockwise";
        break;
    }
}
float NewEncoder::Percentage()
{
    return (float)steps / (float)maxResolution;
}
float NewEncoder::PercentageOfTurn()
{
    return (float)(steps % maxResolution) / (float)maxResolution;
}
float NewEncoder::Radians()
{
    return (2 * PI * PercentageOfTurn());
}
float NewEncoder::Degrees()
{
    return (360 * PercentageOfTurn());
}
