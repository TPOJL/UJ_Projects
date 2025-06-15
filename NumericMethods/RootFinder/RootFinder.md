## Hybrid Zero-Finding: Bisection + Secant

**Language**: C++

### Problem Statement
Implement a function that combines the global convergence of the bisection method with the fast local convergence of the secant method to find a root of a continuous function f on an interval [a, b].

**Function signature**:
```cpp
double findZero(
    double (*f)(double),  // function whose zero we seek
    double a,             // left endpoint of interval
    double b,             // right endpoint of interval
    int M,                // maximum allowed calls to f
    double eps,           // required accuracy in f(x)
    double delta          // required accuracy in x
);
