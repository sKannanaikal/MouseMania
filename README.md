# Mouse Mania
## Sean Kannanaikal's CSEC 473 Red Team Tool

## Overview

This is an executable program that users can pass in a variety of command line arguments to modify the functionality of the mouse in certain ways.  The features include being able to reduce or increase the mouse sensitivity to either extremely high or low.  In addition, an individual can swap the functionality of right click and left click.  Finally, one can randomly move the mouse to another area of the screen.

## Installation instructions

There are mainly two ways you can install this tool.

  1. You can simply download this github repo and just run the executable file within the repository from the cli while passing command line arguments
  2. You can compile from src and create the executable on your own if for whatever reason you do not want to run this executable directly

## Features

### decrease
This command will lower the mouse sensitivty to the lowest possible value allowed by the windows operating system.

### increase
This command will increase the mouse sensitivty to the highest possible value allowed by the windows operating system.

### resetspeed
This command will set the mouse sensitivity to the default value according to the windows operating system.

### swap
This command will swap the functionality of the left and right click buttons on the mouse.

### resetbuttons
This command will reset the functionality of the left and right click buttons of the mouse back to the original functions.

### reverse
This command will reverse the x coordinate and y coordinate of the current position of the mouse with each other and move the mouse to another location on the screen.

## Examples

```
.\mousemania.exe decrease
```

```
.\mousemania.exe swap
```
