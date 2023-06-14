# Functions explanation

All the functions of the library briefly explained

[Back](README.md#methods)

### begin()
`myEnc.begin(CLK, DATA)` \
`myEnc.begin(CLK, DATA, BUTTON)` \
`myEnc.begin(CLK, DATA, BUTTON, Steps per turn)` 

There exist three ways to use the function `begin()`, calling it with different parameters.

The use of one or another method depends on the initial values that you need. If you do not enter a switch button pin, it won't initialize any pin for that matter. Also, if you do not explicitly assign the number of *steps per turn* it will default to *30 steps per turn*:
```cpp
#include <NewEncoder.h>

// Initialize three encoders
NewEncoder myEnc1;
NewEncoder myEnc2;
NewEncoder myEnc3;

void setup()
{
    // 1. Defines the pins where the CLK and DATA
    // (or A and B) pins are connected
    myEnc1.begin(2, 3);

    // 2. Defines the pins where the CLK and DATA
    // (or A and B) pins are connected and also
    // the attached switch button
    myEnc2.begin(4, 5, 6);
    
    // 3. Defines the pins where the CLK and DATA
    // (or A and B) pins are connected, the attached
    // switch button, and the number of steps for
    // each complete turn of the encoder (if you do
    // not need the switch button attached you can
    // simply put a '0' on the button parameter)
    myEnc3.begin(7, 8, 9, 60);
}
```
### Reset()
`myEnc.Reset() (void)`

The `Reset()` function puts the step counter to zero so it can start reading again.

### SetResolution()
`myEnc.SetResolution(new resolution) (void)`

Changes the number of steps for each complete turn of the encoder to the specified number.
### Update()
`myEnc.Update() (void)`

You must try to call the function `Update()` as frequently as possible in order to not miss any incoming signal from the encoders.
### ButtonPressed()
`myEnc.ButtonPressed() (bool)`

Returns `true` if the button is being pressed at the moment, `false` otherwise
### GetSteps()
`myEnc.GetSteps() (int)`

Get the current number of steps of the encoder. For each step it takes clockwise it increments by one and for each step counterclockwise it decrements by one too, so the final count can be either positive, if the majority of the steps were taken clockwise, or negative, if not.

### GetDirection()
`myEnc.GetDirection() (Direction)`

Returns the direction of the last taken step in a Direction enum format.

The ``Direction`` enum can take the values **"None", "Clockwise" and "Counterclockwise"** depending where the encoder is turning towards.

### GetDirectionName()
`myEnc.GetDirectionName() (String)`

The function `GetDirectionName` returns the actual name in `string` format. This comes specially handy when you need to print the name of the direction of rotation. The possible names are the same of the ``Direction`` enum ones.
### Turns()
`myEnc.Turns() (float)`

This function returns the number of steps taken in total by the encoder. This means, for example, that if the encoder was rotated three and a quarter turns, the value of the `Turns()` method will be *'3.25'*.
### PercentageOfTurn()
`myEnc.PercentageOfTurn() (float)`

The function `PercentageOfTurn()` outputs the position of the encoder as a number between '0' and '1', where '0' is the starting position, '0.5' (50%) is half a rotation, and so on.
### Radians()
`myEnc.Radians() (float)`

This method converts the position of the encoder into an angle in radians (from 0 to 2π). This comes in handy if you need to use the obtained data for any other calculation that require the use of radians.
### Degrees()
`myEnc.Degrees() (float)`

The method `Degrees()` converts the position of the encoder into an angle in degrees (from 0º to 360º). Specially useful when you need to perform further trigonometric calculations with the acquired data.
