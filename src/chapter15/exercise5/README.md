#15.5 Call in Order

Suppose we have the following code:

    public class Foo {
    
        public Foo() { ... }
        public void first() { ... } 
        public void second() { ... } 
        public void third() { ... }
      
    }

The same instance of Foo will be passed to three different threads. Thread-A will call _first_, thread-B will call _second_ and thread-C will call _third_. Design a mechanism to ensure that _first_ is called before _second_ and _second_ before _third_. 

_#417_
_#433_
_#446_
