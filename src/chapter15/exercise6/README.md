#15.6 Synchronized Methods

You are given a class with synchronized method A and a normal method B. 
If you have two threads in one instance of a program, can they both execute A at the same time ? Can they execute A and B at the same time ? 

_#429_ 

They cannot both execute method A but they can execute method A and method B.

In case of A java class with a synchronized method, the java runtime allows only one single thread at the time to invoke the  synchronized method and it blocks all the other threads until the running one has exited from synchronized.

This constraint guarantees that changes to the state of the object are visible to all following threads.


Since method B is not synchronized it is not considered when evaluating concurrency constraint.