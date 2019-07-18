Portable snake game written in c for terminal/winconsole with scaleable resolution
===

The game uses my simple cursor manipulation library and scales with terminal resolution.  
requires [jlib](https://github.com/jarekt/jlib) - ~~download it manually or run the getjlib python script~~ jlib included with v1.2 for added convenience

## How to run
### Precompiled Executables
- you can get a precompiled binary(executable) file for your system in the releases tab
### Manual compilation
- **linux**: cd into the downloaded repo folder and type: *gcc snake.c jlib/src/linux.c -o snake*
- **windows**: install microsoft visual studio and add ***snake.c jlib.h and windows.c*** to your project, then build
### Cmake
- **cmake support added *!!***
- for some compilers such as mingw you need to edit the CMakelists.txt of jlib

## Demo pictures
![high_res](img/snake1.png)
* works with different resolutions

![low_res](img/snake2.png)
* low res example running in [cool retro term](https://github.com/Swordfish90/cool-retro-term)

![windows](img/windows.png)
* works even on windows!

## Controls
- w - up
- s - down
- a - left
- d - right
- p - pause
- q - quit


## Known problems
- the speed increase value (when snake eats food) should be changed to a more fun value (this can be edited in the detect collision function)
- you cannot resize your game when it's running - it will mess up the screen