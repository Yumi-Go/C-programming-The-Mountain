# C-programming-The-Mountain
[2021-22] C programming module

The Mountain

This program wakes up at the bottom of a mountain. The whole area is shrouded in deep fog so you only have visibility at a short distance around. My goal is to get to the top of the mountain in as little time as possible.
The landscape is implemented as a 2D matrix on top of which a mountain of a given height and with some irregularities (plateaus) has been placed. The mountain has a single peak. Each element of the 2D matrix contains a value that represents the altitude (height) of that cell, with the mountain peak representing the highest point in the lanscape, or the maximum matrix value.
I can't access to the 2D matrix, or the matrix’s dimensions (height and width). The only thing I can do is make calls to the function

void generate_view(float view[VIEW_SIZE][VIEW_SIZE], int center_y, int center_x)

that will populate a 2D view array from the landscape matrix centered on the center_y and center_x coordinates (resp row and column). Every time I call this function the program will increment my call count with the goal being to implement a search solution that makes the least calls to generate_view.

When this program believe that it has found the peak at a position x,y it calls the function int declare_peak(x,y). The function will return 1 (true) if the peak is correctly identified or 0 (false) otherwise. This can call this function any number of times, however every time it is called it will increment my call count and this will add up to my total.

* NOTE: The generate_view function will stop working after it’s been called as many times as the number of cells in the landscape matrix. Same for declare_peak which will only return 0 after that point.

This is effectively a search problem and there are various possible solutions:
  • brute force searching through the matrix – although I don’t know the matrix dimensions (number of rows and columns) so I perform some exploration at first
  • random search
  • gradient-based hill climbing.

* NOTE: The y coordinates represent the row index in a 2D matrix, while x represents columns.
