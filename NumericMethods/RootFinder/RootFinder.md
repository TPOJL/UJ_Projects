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
```
Requirements

Maintain a counter of f–calls; do not exceed M.

If f(a) * f(b) ≤ 0 and a secant step would take you outside [a, b], use a bisection step instead to maintain bracketing.

Stop when either |f(x0)| ≤ eps or the absolute change in x is ≤ delta.

Return the approximation x0.

Input / Output

Your C++ file should:

Include the findZero function implementation.

Demonstrate usage in main() by:

Defining a test function f.

Calling findZero(f, a, b, M, eps, delta).

Printing the result with full double precision.
