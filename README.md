# Minesweeper Game in C

## Introduction
This Minesweeper game is implemented in C and challenges players to clear a 10x10 grid without detonating any hidden mines. With each successful move, the player's score increases, and bonus points are awarded for uncovering special cells.

## Features
- **Interactive Gameplay:** Enter x and y coordinates via the command line.
- **Scoring System:** Points are earned with each safe move, and bonuses enhance the score.
- **Dynamic Grid:** Mines and bonus points are placed randomly at the start.
- **Endgame Scenarios:** The game ends when a mine is triggered or all safe cells are revealed.

## Implementation
- Utilizes a 2D array to represent the game board.
- Employs queues for managing coordinates and game logic.
- Implements functions for board setup, gameplay, and user interaction.
- Encourages strategic thinking and careful consideration of each move.

## How to Play
Compile the C code and run the executable. Follow the prompts to enter the x (vertical) and y (horizontal) coordinates within the grid range of 0 to 9. Uncover safe cells and collect bonuses, but be cautious – stepping on a mine ends the game!

## Winning the Game
To win, uncover all cells without mines. Keep track of suspected mine locations and use deductive reasoning to avoid them. Can you clear the board and achieve the highest score?

## License
[MIT License](LICENSE.md)

---

Enjoy the game and may your moves be ever in your favor!
