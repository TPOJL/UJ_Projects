# Hermite Interpolation Polynomial

**Language**: C++

## Problem Statement

Compute the value of the Hermite interpolation polynomial and the coefficients of that polynomial given a set of nodes, function (or derivative) values, and query points.

## Submission

Submit **one file** containing the complete solution including the `main` function to the BaCa system.

## Numerical Accuracy

Your program’s results must match the reference solution within the following tolerances:
- **Absolute tolerance**: `1e-14`
- **Relative tolerance**: `1e-10`

Results with error smaller than these thresholds will also be accepted.

## Input Format

M N
X1 X2 ... XM
Y1 Y2 ... YM
T1 T2 ... TN

markdown
Копировать
Редактировать

- `M` — number of Hermite nodes (`1 ≤ M ≤ 100`)
- `N` — number of query points (`1 ≤ N ≤ 100000`)
- `Xi` — interpolation nodes (a non‑decreasing sequence of `double`)
- `Yi` — values of the function **or** its derivatives at the corresponding nodes (see Hermite interpolation specification for details)
- `Ti` — points where the Hermite polynomial should be evaluated

## Output Format

Print `N` lines. Each line should contain the value of the Hermite interpolation polynomial at `Ti`, in full double precision.
