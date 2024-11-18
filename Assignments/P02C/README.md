## P02C - Knuckle Bones
### Ashley Flores
### Description:

This program digitally recreates the game "Knucklebones," featuring an interface built with ncurses. Players engage with the game through classes like Grid, Button, Logger, and Input. The project is currently a work in progress, the goal is to place dice on the grid and score more points than your opponent by following a few key rules.

### Files

|   #   | File            | Description                                        |
| :---: | --------------- | -------------------------------------------------- |
|   1   | [game.cpp](./hello_ncurses.cpp)        | Main driver of my project that launches game and overal flow. |
|   2   | [button_class.hpp](./hello_ncurses.cpp) | Adds button to the game in order to interact with it.      |
|   3   | [color_class.hpp](./hello_ncurses.cpp)      | Color customizes the game interface.               |
|   4   | [dice_class.hpp](./hello_ncurses.cpp)   | Creates a rectangular dice                         |
|   5   | [grid_class.hpp](./hello_ncurses.cpp)   | Dice number value is placed here                   |
|   6   | [logger_class.hpp](./hello_ncurses.cpp)      | Helper class that assists with logging events of the game. |
|   7   | [input_class.hpp](./hello_ncurses.cpp)      | Display the welcome message on the main screen. |

### Instructions

- Use the cd command to change to the directory containing game.cpp and the necessary header files.
- Compile the code using g++ with the ncurses library.
- Execute the compiled program.

##  Work in Progress

### Challenges Encountered

#include errors detected. Please update your includePath. Squiggles are disabled for this translation unit (/home/arflores1204/2143-OOP/2143-OOP/Assigments/P02C/main.cpp).

cannot open source file "stddef.h" (dependency of "buttonClass.hpp"). Please run the 'Select IntelliSense Configuration...' command to locate your system headers.

cannot open source file "stddef.h" (dependency of "diceClass.hpp"). Please run the 'Select IntelliSense Configuration...' command to locate your system headers.
