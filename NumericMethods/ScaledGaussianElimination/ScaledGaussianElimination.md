### Solving a System of Linear Equations using Scaled Gaussian Elimination

Function Signature:

    Vector solveEquations(
        const Matrix & A,   // Matrix A
        const Vector & b,   // Vector b
        double eps          // Allowed error tolerance
    );

Description:

Implement a function to solve the system of linear equations:

    A * x = b

Where:
- A is a square matrix of size n × n,
- x and b are vectors of size n,
- The maximum value of n is 3000,
- The size n can be retrieved using the .size() method on both the matrix and the vector,
- The system is guaranteed to have exactly one unique solution.

Requirements:

To pass all tests, your implementation must satisfy the following:

1. **Scaled Partial Pivoting**:
    - During the forward elimination step, select the pivot row based on the ratio:
      
          |A[i][k]| / scale[i]
      
      where `scale[i]` is the maximum absolute value in row i.
    - Compute the scale vector only once at the beginning of the algorithm.

2. **Iterative Refinement**:
    - After computing the initial solution `x`, apply iterative improvement until the solution satisfies the desired accuracy `eps`.
    - This helps reduce numerical errors and improve precision.

Notes:
- You are solving a system of linear equations using a numerically stable version of Gaussian Elimination.
- Iterative refinement usually involves computing the residual vector `r = b - A*x`, solving `A*delta = r`, and updating `x += delta`, repeating until the norm of the residual is below `eps`.

Assumptions:
- The matrix A is non-singular.
- The input data is always valid.
- You can assume memory usage and performance are acceptable for n ≤ 3000.
