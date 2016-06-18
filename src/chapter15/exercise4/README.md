#15.4 Deadlock-Free Class

Design a class that wich provides a lock only if there are no possible deadlocks. 
 

We can avoid deadlock by knowing all the resources to lock in advance, or we can use in order locking of resources and no holding
In the C++ 11 there's in the namespace std a function to lock all the resources listed or not locking at all.
std::lock( ... ... ) 

_422_
_434_


