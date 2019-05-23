Snake game written in c for terminal/winconsole with scaleable resolution
===

The game uses my simple cursor manipulation library ([jlib](https://github.com/jarekt/jlib)) and scales with terminal resolution.

## demo pictures
![high_res](img/snake1.png)
* works with different resolutions

![low_res](img/snake2.png)
* low res example running in [cool retro term](https://github.com/Swordfish90/cool-retro-term)

## known problems
* the speed increase (when the snake eats food) is loosely dependent on the terminal resolution, but is a value that's by no means actually fun gameplay-wise. -> the speed increase value can be changed in the detect collision function

Tested on manjaro linux, compiled using gcc.
