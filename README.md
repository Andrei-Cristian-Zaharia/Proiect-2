# Description

The game "Repeat the colors" is a memory game. We have four colors (LEDs) and four buttons. The microcontroller will generate a string of random numbers whose length will increase after each stage in which there was a match between the LEDs on and the buttons being pressed. The string must be transposed in color. The player will have to press the corresponding buttons (in order) with the way the LEDs lit up. When the player makes a mistake, a maximum score will be set, and at the push of a button, it will be possible to restart the game. The current score will be displayed on an LCD display, and will be updated after each round. Using one (or more) switches will set the difficulty of the game. The degree of difficulty will consist in the speed with which the LEDs will light up, respectively the waiting time between pressing two buttons by the player.

# Improvements

- Reset button;
- An LED that is functional when the color sequence is repeated automatically;
- Adding a speaker (each LED has its own sound that is emitted when pressed);
- Adding a switch (when in mode 1, the game is running and in mode 2,
 for each button, we will have a set of colors, which will also emit the sounds preset by each LED);

# Components

- 1 breadboard;
- arduino uno
- LCD with I2C adaptor;
- 1 buzzer;
- 5 leds;
- 1 switch;
- 4 buttons;
- wires male-male;
- wires male-female;
- 220 kOhm ( 5 resistors );
- 1 kOhm ( 4 resistors );

# Schematic

![Fritzing drawing](Images/sch.png)
