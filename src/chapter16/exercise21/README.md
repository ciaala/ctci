#16.21 Sum Swap
Given two arrays of integers, find the pair of values (one value from each array), that can swap to give the two arrays the same sum.


## Brute Force
Sort the arrays and sums
sum_a
sum_b

(sum_a + sum_b) / 2 -> final_sum


loop in a for elm_a
    find in b elm_b: (final_sum == sum_b + elm_a - elm_b)
                --> (elm_a + (final_sum - sum_b)) = elm_b
-> couple