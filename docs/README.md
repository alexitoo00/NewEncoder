[![GitHub issues](https://img.shields.io/github/issues/alexitoo00/NewEncoder.svg)](https://github.com/alexitoo00/NewEncoder/issues)
[![Fork](https://img.shields.io/github/forks/alexitoo00/NewEncoder.svg)](#)
[![Stars](https://img.shields.io/github/stars/alexitoo00/NewEncoder.svg)](#)
[![License](https://img.shields.io/github/license/alexitoo00/NewEncoder.svg)](#)
[![Total Downloads](https://img.shields.io/github/downloads/alexitoo00/NewEncoder/total.svg)](https://github.com/caiofrota/cf-arduino-lib-rotary-encoder/releases)
[![Website](https://img.shields.io/badge/alexitoo00-green.svg)](https://github.com/alexitoo00)


# New Encoder

Version 1.0.2

This library is an attempt of obtaining the most properties from rotary encoders as possible. You can get the direction of the last rotation, set the number of steps per turn of your exact model of encoder and even convert the rotation into degrees or radians.

## Compatibility
This library was tested on **avr, megaavr, sam, samd, nrf52, mbed, mbed_nano, mbed_rp2040** architectures so you should be able to use it without problems.

## Releases
To use this library, open the Library Manager in the Arduino IDE, type in "NewEncoder" and install it from there. More on that in the following [link](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries)
- 1.0.2

## Usage
This library allows an Arduino board to read various parameters from rotary encoders. This devices use two square signals that can be translated into how much the encoder rotates. With this library you can read the rotation of each encoder as well as make usage of the integrated switch button.

The NewEncoder library supports various simultaneous encoders without the need of interrupt pins.


To make use of this library you first need to include the library file and create an instance of an encoder:
```cpp
#include <NewEncoder.h>

NewEncoder myEncoder;
```

## Circuit
Usually, rotary encoders have **5** pins in total: **CLK** (or A pin), **DATA** (or B pin), **SW** (Switch button), **power** and **ground**. The **power** wire should be connected to the **5V** pin on the Arduino board. The **ground** is connected to any of the **ground** pins of the Arduino. The **CLK**, **DATA** and **SW** pins can be connected anywhere else in the board and we must declare which pin is connected to which encoder in the [`begin()`](#begin) function.
- Schematic **(WIP)**
![](/img/scheme.jpg)

## Examples
[Basic read](/examples/BasicReadExample/BasicReadExample.ino): *Demonstrates the functionality of the methods of the library*

[Simultaneous encoders](/examples/SimultaneousEncoders/SimultaneousEncoders.ino): *Shows how to handle multiple encoders at the same time*


## Methods

You can see the list of all functions along with some information about the use cases of each one in this *[functions explanation file](FunctionExplanation.md)*\
\
[begin()](./FunctionExplanation.md#begin)

[Reset()](./FunctionExplanation.md#reset)

[SetResolution()](./FunctionExplanation.md#setresolution)

[Update()](./FunctionExplanation.md#update)

[ButtonPressed()](./FunctionExplanation.md#buttonpressed)

[GetSteps()](./FunctionExplanation.md#getsteps)

[GetDirection()](./FunctionExplanation.md#getdirection)

[GetDirectionName()](./FunctionExplanation.md#getdirectionname)

[Turns()](./FunctionExplanation.md#turns)

[PercentageOfTurn()](./FunctionExplanation.md#percentageofturn)

[Radians()](./FunctionExplanation.md#radians)

[Degrees()](./FunctionExplanation.md#degrees)



## Support or Contact

You can always contact me at [alexandrocb2013@gmail.com](mailto:alexandrocb2013@gmail.com) for questions and I'll help you sort it out.

## Issues

Find a bug or want to request a new feature? Please let me know by [submitting an issue](https://github.com/alexitoo00/NewEncoder/issues).

## Authors

* **Alex Casal** - *Initial work* - [alexitoo00](https://github.com/alexitoo00) | []()

## License

This project is licensed under the MIT License - see the [LICENSE](../LICENSE) file for details