#15.2 Context Switch
_How would you measure the time spent in a context switch?_

I would write a program with two threads that continuously yields to each other and that, as the only task, they measure the time before and after the yield.
 

