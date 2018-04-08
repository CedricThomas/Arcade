
# Cpp_Arcade utilisation

Epitech project realised in cpp within the second year

## Installing
But first make sure you got the:
                                - Ncurses
                                - SDL2
                                - SFML
librairy installed, on your work station.
In other case [Google](google.com) is your friend and the one who best know how to install them.

## Build the project

To compile use:
```sh
$ make
```

To only compile the core use:
```sh
$ make core
```

To only compile libs use:
```sh
$ make graphicals
```

To only compile games use:
```sh
$ make games
```

then execute the arcade executable followed by the first graphic lib you want (you can always change it later)
```sh
$  ./arcade lib_arcade_ncurses.so 
```
## The Menu
Once in the menu, use the right and left arrow key to choose between 
- SDL2
- Ncurses
- SFML

You can also use the up and down arrow key to choose the game you want to play.
- Pacman
- Rainbow Nibbler

If you're a perfectionnist or just want to share you score with friend, just type something in the menu and it will be your player name, otherwise your default name will be player.
By the way you can press **Tab** to see the high score.

Once you got all the parameters you want just press **Enter** and enjoy our Arcade.

## PacMan
The good old arcade game [PacMan](http://www.pacman1.net) (don't mistake him for Tupac thought).
As the original:
- Change the graphics with **Q** or **D**
- Explore the maze with the arrow key.
- Eat as much as possible the food is great there.
- Beware of the shining ghost, unless you'll eat the Forbidden fruit then beware of the hungry Pac Man (for 10 secondes).


## Rainbow Nibbler
The [Nibbler](https://archive.org/details/arcade_nibbler) is an old arcade game.
The rules are simple:
- Change the graphics with **Q** or **D**
- Use the arrow key to move the snake around.
- Don't hit a wall (that be dumb).
- If you're hungry there are plenty of apples, they taste better than your tail. But watchout gluttony is a bad vice.
- Sometimes there are shiny things, snakes loves shiny things.
- Press **Space Bar** for some fun.

## Group Compliance

see the [explanations](README.md)

## Technical explantions
see the [technical documentation](TECHNICAL_DOCUMENTATION.md)

# Authors - It's a prank, bruh!
- **Cédric Thomas**
- **Auguste Ziegler**
- **Jérémie Bruhwiler**
