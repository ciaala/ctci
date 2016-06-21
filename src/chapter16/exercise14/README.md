#16.14 Best Line
Given a two-dimensional graph with points on it, find a line which passes the most number of points.


## Brute Force
- Write a matrix of line connecting each couple of points O(n^2)
- Evaluate all lines against each point O(n^2 * n) -> memorize the maximum found

## Smart Brute Force
If we create a hash table with the line as a key and a counter as the value, we just need to create the initial matrix _n x n_ of lines and the same time we are counting and looking up.

## Can we partition space ?
We can create a logical partitioning of points in a BSP tree. So we can check if a line cross this space partitioning before testing the points inside.

_#491_
_#520_
_#529_
_#563_


