# Snake game in c for terminal/winconsole with scaleable resolution

The game uses my simple cursor manipulation library (jlib) and scales with terminal resolution.

## known problems
* the speed increase (when the snake eats food) is loosely dependent on the terminal resolution, but is a value that's by no means actually fun gameplay-wise. -> the speed increase value can be changed in the detect collision function

Tested on manjaro linux, compiled using gcc.
