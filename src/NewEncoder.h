#include <Arduino.h>

class NewEncoder
{
private:
    // Pin out
    uint8_t _outA;
    uint8_t _outB;
    uint8_t _button;

    // Variables
    int maxResolution = 20;
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
    NewEncoder::NewEncoder(uint8_t outA, uint8_t outB, int resolution, uint8_t button);

    void begin(uint8_t outA, uint8_t outB, int resolution, uint8_t button);
    void begin(uint8_t outA, uint8_t outB, int resolution);
    void begin(uint8_t outA, uint8_t outB);

    void SetResolution(int resolution);

    void Update();
    bool ButtonPressed();

    int GetSteps();
    Direction GetDirection();

    float Percentage();
    float PercentageOfTurn();
    float Radians();
    float Degrees();
};
NewEncoder::NewEncoder(uint8_t outA, uint8_t outB, int resolution = 20, uint8_t button = 0)
{
    begin(autA, outB, resolution, button);
}

// Constructor with optional parameters 'resolution' (default 20) and 'button'
void NewEncoder::begin(uint8_t outA, uint8_t outB, int resolution, uint8_t button)
{
    _outA = outA;
    _outB = outB;
    _button = button;

    maxResolution = resolution;

    pinMode(_outA, INPUT);
    pinMode(_outB, INPUT);

    if (_button != 0)
        pinMode(_button, INPUT_PULLUP);

    DIRECTION = None;
}
void NewEncoder::begin(uint8_t outA, uint8_t outB)
{
    begin(outA, outB, 20, 0);
}
void NewEncoder::begin(uint8_t outA, uint8_t outB, int resolution)
{
    begin(outA, outB, resolution, 0);
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
