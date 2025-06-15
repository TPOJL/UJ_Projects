Successive Over-Relaxation (SOR) Method

Problem Statement

The SOR method is an iterative technique for solving linear systems Ax = y, where A is an N × N matrix, and x, y ∈ ℝᴺ. For symmetric positive-definite matrices and relaxation parameter ω ∈ (0,2), SOR converges to the solution from any initial guess.

Implement SOR for banded symmetric sparse matrices. If there are M off-diagonals on each side of the main diagonal, then in row k, nonzero entries occur only for j where k-M ≤ j ≤ k+M.

Input

Line 1: Integer N (matrix size)

Line 2: Integer M (off-diagonals count)

Next M lines: i-th line has N-i real numbers (i-th sub-/super-diagonal)

Next line: N real numbers (main diagonal)

Next line: N real numbers (vector y)

Next line: N real numbers (initial guess x⁽⁰⁾)

Next line: Real number ω (relaxation parameter)

Next line: Integer L (iterations count)

Output

x⁽ᴸ⁾ after L iterations:

Each of N components on its own line

Scientific notation with 10 decimal places

Format: ±d.ddddddddddde±dd

Error Tolerance

Results rejected if:

|x - x̄| > εₐ OR |x - x̄|/|x| > εᵣ (for x ≠ 0)

Where εₐ ≈ 10⁻¹² and εᵣ ≈ 10⁻⁸

Example 1

Input (file1.in):

text

7

2

1 2 1 2 1

2 -1 3 1 3 -1

5 6 7 8 9 10 11

8 9 11 16 15 14 11

2 3 2 3 2 3 2

1.5

1

Output (file1.out):

text

-1.0000000000e+00

2.5000000000e-01

-7.3214285714e-01

3.1808035714e-01

-2.6432291667e-01

9.2352120536e-01

6.6197874391e-01

Example 2

Input (file2.in):

text

10

1

1 -1 2 1 3 -1 1 2 2

8 9 10 9 8 5 10 9 7 5

7 -8 5 -7 3 -5 7 -5 4 -3

2 1 2 1 2 1 2 1 2 1

1.3

5

Output (file2.out):

text

9.9940568551e-01

-9.0904662229e-01

6.0991796223e-01

-1.0130102945e+00

1.0831324690e+00

-1.5137961826e+00

6.1540772283e-01

-8.7787343356e-01

1.1233322463e+00

-1.0523066240e+00
