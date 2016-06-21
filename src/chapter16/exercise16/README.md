#16.16 Sub Sort
Given an array of integers, write a method to find the indices _m and n_ such that if you sorted elements _m_ through _n_, the entire array would be sorted.
 Minimize (m - n) (that is find the smallest such sequence).

## Smart
- Setup Phase
  - we setup the algorithm with m = 0 and n = array.length
  - induction indexes _i and j_ starts at _m and n_
- Loop Phase
  - we proceed from start and from end through the center:
  - at each step we check if the next adjacent elements is in order between the indexes _m & n_ if so we move m and n
  - once one side is not in order we lookup for the first position where we should insert the element before/after the indexes we reassign _m/n_ to that value
- Loop ends when the induction indexes reaches m and n

