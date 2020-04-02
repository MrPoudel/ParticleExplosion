## Output

![Screen](https://github.com/MrPoudel/ParticleExplosion/blob/master/SDL2Test.png)

# ParticleExplosion
C++ Project that uses SDL2 library ( openGL and Direct3D)

This project is based on the lectures from `cave of programming` :[YouTube video series](https://www.youtube.com/watch?v=1MKhigIml3E&list=PLmpc3xvYSk4wDCP5zjt2QQXe8-JGHa4Kt).
This project provides some basic concepts about 3D gaming.

## Prerequisites
1. Install the SDL on your machine
2. Set up the build system properly

## Using uncrustify with repo

A python script needs to automate the process of uncrustify. The script should detect automatically all the source files that have been changed and should run the uncrustify to all those changed files.
But, currently, it has been done manually as follows:

./build/extern/uncrustify/uncrustify -c /home/playground/Desktop/ParticleExplosion/extern/uncrustify/forUncrustifySources.cfg --no-backup /home/playground/Desktop/ParticleExplosion/main.cpp
