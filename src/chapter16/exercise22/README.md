#16.22 Langton's Ant:
An ant is sitting on an infinite grid of black and white squares. It initially faces right. At each step, it does the following:
- At a white square, flips the color of the square, turn 90 degrees left (counter-clockwise) and move forward one unit.
- At a black square, flips the color of the square, turn 90 degrees right (counter-clockwise) and move forward one unit.

Write a program to simulate the first K moves that ant makes and print the final board as a grid.

Note that you are not provided with the data structure to represent the grid. This is something you must design by yourself. The only input to your method is K. You should print the final grid and return nothing.
The method signature might be something like void printKMoves(int k).