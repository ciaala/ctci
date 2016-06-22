#16.19 Pond Sizes
You have an integer matrix representing a plot of land, where the value at that location represents the height above the sea level. A value of zero indicates water. A pond is a region of water connected vertically, horizontally or diagonally. The size of the pond is the total number of connected water cells. Write a method to compute the sizes of all ponds in the matrix.

_#674_
_#687_
_#706_
_#723_

## Author
We need to find between the adjacent cells a pond.
Brute force of each cell of the matrix -> 0(_n x m x 8_) ~ 0(n^2)

We proceed in an ordered way we lower the cost to 0(_n x m_ x 3)

If we find an adjacent pond we join it, if we find multiple pond we join them.

We need to store x each cell the pond and the reverse map for each pond the list of cells


