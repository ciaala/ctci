#16.17 Contiguous Sequence
You are given an array of integers both positive and negative, find the contiguous sequence  with the largest sum, return the sum.

## Author
- ~~We need to compute for each negative! cell the gradient to move left and to move right -> it is not enough to aggregate.~~
- We partition the array in isle of sum of positive values and negative values
- We keep aggregating isles from left to right
    - 2 positives and a negative at the same time
    - when the sum of the isles is greater then single positive elements
    - when there's nothing to aggregate positive we move to the next to aggregate


## Book
Solution is implemented
We scan from left to right we keep track at every element of the positive sum
we reset the sum as soon as we find an

