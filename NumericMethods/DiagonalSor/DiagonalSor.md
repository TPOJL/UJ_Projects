### Problem Statement
The Successive Over-Relaxation (SOR) method is an iterative technique for solving linear systems \(A x = y\), where \(A\) is an \(N times N\) matrix, and \(x, y\in\mathbb{R}^N\). For symmetric positive-definite matrices and relaxation parameter \(\omega\in(0,2)\), SOR converges to the solution from any initial guess.

Implement SOR for banded symmetric sparse matrices. If there are \(M\) off-diagonals on each side of the main diagonal, then in row \(k\), nonzero entries may occur only for \(j\) such that \(k-M\le j\le k+M\).

### Input
- Line 1: Integer \(N\), the matrix size.  
- Line 2: Integer \(M\), the number of off-diagonals on each side.  
- Next \(M\) lines: the \(i\)-th line lists \(N-i\) real numbers giving the \(i\)-th sub-/super-diagonal (from row \(i+1\) to row \(N\)).  
- Next line: \(N\) real numbers for the main diagonal.  
- Next line: \(N\) real numbers for the right-hand side vector \(y\).  
- Next line: \(N\) real numbers for the initial guess \(x^{(0)}\).  
- Next line: Real number \(\omega\), the relaxation parameter.  
- Next line: Integer \(L\), the number of iterations to perform.

### Output
Output \(x^{(L)}\) after \(L\) SOR iterations: each of the \(N\) components on its own line, in scientific notation with 10 decimal places.

### Notes
Results will be compared with both absolute error \(\varepsilon_a\) (around \(10^{-12}\)) and relative error \(\varepsilon_r\) (around \(10^{-8}\)). A result \(\bar{x}\) is rejected if

\[
|x - \bar{x}| > \varepsilon_a \quad\text{or}\quad \frac{|x - \bar{x}|}{|x|} > \varepsilon_r \quad(\text{for } x \neq 0).
\]

### Example 1
**Input file (`file1.in`):**
```plaintext
7
2
1 2 1 2 1
2 -1 3 1 3 -1
5 6 7 8 9 10 11
8 9 11 16 15 14 11
2 3 2 3 2 3 2
1.5
1
Expected output (file1.out):

-1.0000000000000000e+00
2.5000000000000000e-01
-7.3214285714285721e-01
3.1808035714285765e-01
-2.6432291666666696e-01
9.2352120535714288e-01
6.6197874391233791e-01
Example 2
Input file (file2.in):


10
1
1 -1 2 1 3 -1 1 2 2
8 9 10 9 8 5 10 9 7 5
7 -8 5 -7 3 -5 7 -5 4 -3
2 1 2 1 2 1 2 1 2 1
1.3
5
Expected output (file2.out):


9.9940568551471820e-01
-9.0904662229329669e-01
6.0991796223201045e-01
-1.0130102944878934e+00
1.0831324689900357e+00
-1.5137961825745920e+00
6.1540772283026224e-01
-8.7787343355916414e-01
1.1233322463475970e+00
-1.0523066239504728e+00
