# Jlib - a simple c lib for cursor control in terminal/winconsole

This library implements a minimal amount of functions for simple cursor manipulation.

- compatible with both linux terminal and windows console
- tested on gcc and microsoft visual studio
- **now cmake compatible *!!!***

## How to use with cmake
- copy jlib to your cmake root folder
- add *add_subdirectory(jlib)  
target_link_libraries((your linking target) jlib)* to your CmakeLists.txt
