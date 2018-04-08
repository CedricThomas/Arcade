# Cpp_Arcade technical documentation

## How to implement new graphics libraries ?

To implement new graphics libs in our Arcade project you need to implement the functions of the [IGraphiclib](../api/IGraphicLic.hpp) interface 

in a class allowing to use an external lib with our tools classes  (see section tools) and interface methods.

### IGraphiclib methods implementation

| Method name  | Utilisation                                                   |
|--------------|---------------------------------------------------------------|
| getName      | Get the name of the library                                   |
| isOpen       | Check if the lib window is open                               |
| closeRenderer| Close the window of the lib                                   |
| openRenderer | Open the window of the lib                                    |
| clearWindow  | Clears the screen of the lib window                           |
| refreshWindow| Displays the buffered frame to the lib window                 |
| drawPixelBox | Draws a PixelBox on the buffer of the lib window              |
| drawText     | Draws a textBox on the buffer of the lib window               |
| pollEvents   | Fetch all the events from the user and saves them             |
| getLastEvent | Unstack the first event of the saved event list and return it |
| clearEvents  | Clear th events stack                                         |
| getScreenSize| Get the X and Y max of the window                             |
| getMaxY      | get the Y max of the window                                   |
| getMaxX      | get the X max of the windows                                  |

(for more informations consult the [interface](../api/IGraphicLic.hpp))

## How to implement new game libraries ?

To implement new game libs in our Arcade project you need to implement the function of the [IGamelib](../api/IGameLib.hpp) interface in a class.

### IGameLib methods implementation

| Method name  | Utilisation                                                                                           |
|--------------|-------------------------------------------------------------------------------------------------------|
| getName      | Get the name of the library                                                                           |
| init         | Initializes the game resources                                                                        |
| stop         | Clean the game resources and stop the game                                                            |
| update       | Allow to the game to calculate periodic event before the rendering (return false when the game is end)|
| refresh      | Allow the game to draw all PixelBox and textBox (clearing and refreshing th lib is required in this method)  |
| getScore     | get the current score of the game                                                                     |

(for more informations consult the [interface](../api/IGameLic.hpp))

## You are not alone! here are some tools!

### [Color](../api/Color.hpp)

This class allow you to bind the colors of each lib in an universal color binding used by every part of the Arcade project.

### [Keys](../api/Keys.hpp)

This class allow you to bind the keys of each lib in an universal key binding used by every part of the Arcade project.

### [PixelBox](../api/PixelBox.hpp)

This class allow you to bind the keys of each lib in an universal key binding used by every part of the Arcade project.


### [Textbox](../api/Textbox.hpp)

This class allow you to bind the keys of each lib in an universal key binding used by every part of the Arcade project.


### [Vect](../api/Vect.hpp)

This class allow you to bind the keys of each lib in an universal key binding used by every part of the Arcade project.