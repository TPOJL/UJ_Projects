## Natural Cubic Spline Interpolation

**Language**: C++

### Problem Statement
Implement a C++ class for natural cubic spline interpolation that, given nodes (x[i], y[i]), constructs a piecewise‑cubic function S(x) satisfying:

- S(x[i]) = y[i] for i = 0..n-1  
- S''(x[0]) = S''(x[n-1]) = 0 (natural boundary conditions)  
- S(x) is continuously differentiable up to second order on [x[0], x[n-1]]

### Interface

```cpp
class spline {
public:
    // Constructor: number of nodes
    spline(int n);

    // Build the spline from arrays x[] and y[]
    // Preconditions: x[] is strictly increasing, length n
    void set_points(double x[], double y[]);

    // Evaluate the spline at point z (x[0] <= z <= x[n-1])
    double operator()(double z) const;
};
