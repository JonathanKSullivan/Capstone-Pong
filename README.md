# Capstone Pong Game - C++ Nanodegree
## Instructions for running the project
---
### Dependencies for Running Code
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* SDL2
  * Installation instructions are linked [here](https://wiki.libsdl.org/Installation)
  
### Basic Build Instructions
1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./Pong`.
## Overview of my code structure
---
- [main.cc]()
-- Contains the game loop and initializes nessesary dependencies.
- [pong.h]()
-- Hold declaerations of the pong class which is used to represent an instance of a game of pong. 
- [pong.cc]()
-- Implementation of `pong.h`. 
- [game_obj.h]()
-- Hold declaerations of the object used in pong, including abstract objects such as GameObject, Paddle and more concrete examples such as Ball, PlayerPaddle and AIPaddle.
- [game_obj.cc]()
-- Implementation of the classes declared in `game_obj.h`. 
- [util.h]()
-- Defined several useful helper function used to detect conlisions and to determine the ball's dynamics.
- [util.cc]()
- Implementation of `util.h`.
## Explanation of how my submission satisfies the necessary rubric
### Loops, Functions, I/O
- **The project demonstrates an understanding of C++ functions and control structures.** The project code is clearly organized into functions and a variety of control structures are used in the project.
- **The project accepts user input and processes the input.** The project accepts input from a user in this case it takes in key events to play a game of pong.
### Object Oriented Programming
- **The project uses Object Oriented Programming techniques.** The project code is organized into classes with class attributes to hold the data, and class methods to perform tasks.
- **Classes use appropriate access specifiers for class members.** All class data members are explicitly specified as public, protected, or private.
- **Class constructors utilize member initialization lists.** All class members that are set to argument values are initialized through member initialization lists.
- **Classes abstract implementation details from their interfaces.** All class member functions document their effects, either through function names, comments, or formal documentation. Member functions do not change program state in undocumented ways.
- **Classes encapsulate behavior.** Appropriate data and functions are grouped into classes. Member data that is subject to an invariant is hidden from the user. State is accessed via member functions.
- **Classes follow an appropriate inheritance hierarchy.** Inheritance hierarchies are logical. Composition is used instead of inheritance when appropriate. Abstract classes are composed of pure virtual functions. Override functions are specified.
- **Derived class functions override virtual base class functions.** 3 member function in an inherited class overrides a virtual base class member function.
### Memory Management
- **The project makes use of references in function declarations.** At least two functions use pass-by-reference in the project code.
- **The project uses destructors appropriately.** Pong class that uses unmanaged dynamically allocated memory.
- **The project uses scope / Resource Acquisition Is Initialization (RAII) where appropriate.** The project follows the Resource Acquisition Is Initialization pattern where appropriate, by allocating objects at compile-time, initializing objects when they are declared, and utilizing scope to ensure their automatic destruction