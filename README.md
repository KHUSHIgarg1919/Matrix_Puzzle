# Matrix_Puzzle

## PROJECT DESCRIPTION 

Matrix Puzzle is an engaging and brain-teasing console-based game implemented in C. The objective of the game is to arrange a series of numbers in ascending order by shifting them within a grid. It's a fun and challenging game that tests your problem-solving skills and strategic thinking.

## RULES OF GAME 

1. You can move only one step at a time by arrow keys.
   ```  
        Move Up   : By Up arrow key
        Move Down : By Dowm arrow key
        Move Left : By Left arrow key
        Move Right: By Right arrow key
   ```
2. You can move number at empty position only.
3. For each valid move, total number of moves will decrease by 1.
4. Winning Situation:<br>
   Numbers in a 3*3 matrix should be in order 1 to 8.
5. You can exit the game at any time by pressing 'E' or 'e'. <br>
   Try to win the game in minimum number of moves.

## GOALS 

* **Entertainment**: The primary goal is to create an enjoyable and challenging game that keeps players engaged and entertained.
* **Problem Solving**: Promote problem-solving skills by requiring players to strategize and think ahead to solve the number arrangement puzzle.
* **Scoring System**: Implement a number of moves that rewards efficient and successful gameplay, encouraging players to improve their performance.
* **User-Friendly**: Create a user-friendly console interface with clear instructions.

## SPECIFICATIONS

* **Grid Generation**: Randomly generate a grid of numbers with one empty space. The grid should have dimensions (e.g., 3x3 or 4x4).
* **User Input**: Accept user input through the keyboard (arrow keys) to control the movement of numbers within the grid.
* **Game Logic**: Implement the rules of the game, ensuring that numbers can be shifted horizontally or vertically and players can only move numbers into empty spaces.
* **Reset and Restart**: Allow players to reset the game and start over if they wish to retry.

## DESIGN

* **Data Structures**: Appropriate data structures such as two-dimensional array is used to represent the game grid, including the numbers and their positions.
* **Functions**: Organize the code into functions to handle different aspects of the game, such as grid initialization, user input processing, and game logic.
* **Random Grid Generation**: Develop a function to generate random initial grids that ensure solvability.
* **Documentation**: Include comments and documentation to explain the purpose and usage of functions and variables in the code.
