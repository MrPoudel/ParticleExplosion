## Output

[![Build Status](https://dev.azure.com/MrPoudel/Test/_apis/build/status/MrPoudel.ParticleExplosion?branchName=master)](https://dev.azure.com/MrPoudel/Test/_build/latest?definitionId=1&branchName=master)
[![Build Status](https://travis-ci.org/MrPoudel/ParticleExplosion.svg?branch=master)](https://travis-ci.org/MrPoudel/ParticleExplosion)
[![Quality Gate Status](https://sonarcloud.io/api/project_badges/measure?project=MrPoudel_ParticleExplosion&metric=alert_status)](https://sonarcloud.io/dashboard?id=MrPoudel_ParticleExplosion)

## Basic

![Screen](https://media.giphy.com/media/L1Kzrlf8D7Oo9m8U4x/giphy.gif)

## With 3x3 box blur algorithm

![Realistic](https://media.giphy.com/media/Masb8ORIR4N4I87G63/giphy.gif)

This .gif is created as follows:

1.  First `Open Broadcaster Software Studio(OBS Studio)` is installed in the Ubuntu machine.

```
sudo add-apt-repository ppa:obsproject/obs-studio
sudo apt update
sudo apt install obs-studio
```

2. Then, screen is recorded in the .mp4 format.
3. Converted the .mp4 vide file in to `.gif` from [giphy.com](https://giphy.com/)


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

```
./build/extern/uncrustify/uncrustify -c /home/playground/Desktop/ParticleExplosion/extern/uncrustify/forUncrustifySources.cfg --no-backup /home/playground/Desktop/ParticleExplosion/main.cpp
```

- A similar result can be achieved with a tool called clang-format.

## Docker integration
TODO: Run the sonar scanner from Docker image...

## New section
