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

```
Input / Output

Your single C++ file (including main) should:

Read integer n (number of nodes).

Read array x[0..n-1] (sorted ascending).

Read array y[0..n-1] (function values).

Read integer m (number of query points).

Read m values z[j].

Construct spline spl(n);

Call spl.set_points(x, y);

For each j from 0 to m-1, output spl(z[j]) on its own line in full double precision.
