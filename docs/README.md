# New Encoder

This library is an attempt of obtaining the most properties from rotary encoders as possible. You can get the direction of the last rotation, set the number of steps per turn of your exact model of encoder and even convert the rotation into degrees or radians.

## Compatibility
This library was tested on **avr, megaavr, sam, samd, nrf52, mbed, mbed_nano, mbed_rp2040** architectures so you should be able to use it without problems.

## Releases
To use this library, open the Library Manager in the Arduino IDE and install it from there.
- 1.0.0

## Usage
This library allows an Arduino board to read various parameters from rotary encoders. This devices use two square signals that can be translated into how much the encoder rotates. With this library you can read the rotation of each encoder as well as make usage of the integrated switch button.

The NewEncoder library supports various simultaneous encoders without the need of interrupt pins.


To make use of this library you first need to include the library file and create an instance of an encoder:
```cpp
#include <NewEncoder.h>

NewEncoder myEncoder;
```

## Circuit
Usually, rotary encoders have 5 pins in total: CLK (or A pin), DATA (or B pin), SW (Switch button), power and ground. The power wire should be connected to the 5V pin on the Arduino board. The ground is connected to any of the ground pins of the Arduino. The CLK, DATA and SW pins can be connected anywhere else in the board and we must declare which pin is connected to which encoder in the [`begin()`](#begin) function.

## Examples
[Basic read](/examples/BasicReadExample/BasicReadExample.ino): Demonstrates the functionality of the methods of the library

[Simultaneous encoders](/examples/SimultaneousEncoders/SimultaneousEncoders.ino): Shows how to handle multiple encoders at the same time


## Methods
[`begin()`](#begin)

[`Reset()`](#Reset)

[`SetResolution()`](#SetResolution)

[`Update()`](#Update)

[`ButtonPressed()`](#ButtonPressed)

[`GetSteps()`](#GetSteps)

[`GetDirection()`](#GetDirection)

[`GetDirectionName()`](#GetDirectionName)

[`Turns()`](#Turns)

[`PercentageOfTurn()`](#PercentageOfTurn)

[`Radians()`](#Radians)

[`Degrees()`](#Degrees)

-----

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