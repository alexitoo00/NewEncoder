#include <Arduino.h>

class NewEncoder
{
private:
    // Pin out
    uint8_t _outA;
    uint8_t _outB;
    uint8_t _button = 0;

    // Encoder variables
    int maxResolution = 30;
    int steps = 0;

    // Encoder tracking variables
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
    void begin(uint8_t clk, uint8_t data, uint8_t button, int resolution);
    void begin(uint8_t clk, uint8_t data, uint8_t button);
    void begin(uint8_t clk, uint8_t data);

    void Clear();

    void SetResolution(int resolution);

    void Update();
    bool ButtonPressed();

    int GetSteps();
    Direction GetDirection();
    String GetDirectionName();

    float Turns();
    float PercentageOfTurn();
    float Radians();
    float Degrees();
};

/// Begin encoder initialization with various options
// Defines the pins where the CLK and DATA (or A and B) pins are connected
void NewEncoder::begin(uint8_t clk, uint8_t data)
{
    _outA = clk;
    _outB = data;

    pinMode(_outA, INPUT_PULLUP);
    pinMode(_outB, INPUT_PULLUP);

    DIRECTION = None;
}
// Defines the pins where the CLK and DATA (or A and B) pins are connected and also the attached switch button
void NewEncoder::begin(uint8_t clk, uint8_t data, uint8_t button)
{
    _button = button;

    if (_button != 0)
        pinMode(_button, INPUT_PULLUP);

    begin(clk, data);
}
// Defines the pins where the CLK and DATA (or A and B) pins are connected, the attached switch button, and the number of steps for each complete turn of the encoder
void NewEncoder::begin(uint8_t clk, uint8_t data, uint8_t button, int resolution)
{
    maxResolution = resolution;

    begin(clk, data, button);
}
// Resets the step count of the encoder to zero
void NewEncoder::Clear()
{
    steps = 0;
}
// Changes the number of steps for each complete turn of the encoder to the specified number
void NewEncoder::SetResolution(int resolution)
{
    maxResolution = resolution;
}
// Update encoder state based on pin changes
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
// Returns true if the button is currently pressed, false otherwise
bool NewEncoder::ButtonPressed()
{
    return (_button != 0) && !digitalRead(_button);
}
// Get the current number of steps of the encoder (positive clockwise, negative counterclockwise)
int NewEncoder::GetSteps()
{
    return steps;
}
// Returns the direction of the last taken step
NewEncoder::Direction NewEncoder::GetDirection()
{
    return DIRECTION;
}
// Returns the name of the direction of the last step taken
String NewEncoder::GetDirectionName()
{
    return (DIRECTION == None)               ? "None"
           : (DIRECTION == Clockwise)        ? "Clockwise"
           : (DIRECTION == Counterclockwise) ? "Counterclockwise"
                                             : "Unknown";
}
// Get the number of complete turns made by the encoder
float NewEncoder::Turns()
{
    return (float)steps / (float)maxResolution;
}
// Get the percentage of one complete turn completed by the encoder
float NewEncoder::PercentageOfTurn()
{
    return (float)(steps % maxResolution) / (float)maxResolution;
}
// Get the position of the encoder in radians (0 rad - 2*PI rad)
float NewEncoder::Radians()
{
    return (2 * PI * PercentageOfTurn());
}
// Returns the position of the encoder in degrees (0º - 360º)
float NewEncoder::Degrees()
{
    return (360 * PercentageOfTurn());
}
