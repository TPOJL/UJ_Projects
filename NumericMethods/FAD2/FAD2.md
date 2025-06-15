Problem D: Jet Propagation for Mixed Partial Derivatives (FAD2)

Language: C++

Problem Statement

Symbolic computation of higher-order derivatives of a function f: ℝ² → ℝ quickly leads to very complex formulas and large numerical errors. Often, the formula for the function is not directly available; its values are computed by a subroutine. In automatic differentiation, basic arithmetic operations and elementary functions are replaced by operations on sequences of Taylor coefficients (or sequences of derivatives) called jets. This technique is known as jet propagation.

Implement jets to compute all partial derivatives of a two-variable function up to second order at given points. For a function f(x,y) and point (x₀,y₀), compute the tuple:


(f(x₀,y₀), fₓ(x₀,y₀), fᵧ(x₀,y₀), fₓₓ(x₀,y₀), fₓᵧ(x₀,y₀), fᵧᵧ(x₀,y₀))


Input

First line: Integer M (0 < M < 10⁶), number of points

Next M lines: Two real numbers xᵢ and yᵢ per line

The function funkcja is provided in funkcja.h:

cpp
template <typename T>
T funkcja(const T &x, const T &y);
