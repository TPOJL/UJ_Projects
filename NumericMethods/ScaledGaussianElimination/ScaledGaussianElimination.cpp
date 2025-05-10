#include "vectalg.h"
using namespace std;

Vector solveEquations(const Matrix& A_input, const Vector& b_input, double eps) {
    int n = A_input.size();
    Matrix A = A_input;
    Vector b = b_input;
    Vector x(n);
    double s[n];
    
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < n; j++) {
            s[i] = max(s[i], abs(A(i, j)));
        }
    }

    for (long long j = 0; j < n - 1; j++) {
        double maxElem = 0;
        long ixg = j;

        for (long long i = j; i < n; i++) {
            double currentElem = abs(A(i, j)) / (s[i]);
            if (currentElem > maxElem) {
                maxElem = currentElem;
                ixg = i;
            }
        }

        for(long long p = 0; p < n; p++) {
            double temp = A(j, p);
            A(j, p) = A(ixg, p);
            A(ixg, p) = temp;
        }
        double temp = b[j];
        b[j] = b[ixg];
        b[ixg] = temp;

        for (long long i = j + 1; i < n; i++) {
            double factor = A(i, j) / A(j, j);
            for (long long k = j; k < n; k++) {
                A(i, k) -= factor * A(j, k);
            }
            b[i] -= factor * b[j];
        }
    }

    for (long long i = n - 1; i >= 0; i--) {
        double sum = b[i];
        for (long long j = i + 1; j < n; j++) {
            sum -= A(i, j) * x[j];
        }
        x[i] = sum / A(i, i);
    }

    Vector r = residual_vector(A_input, b_input, x);
    Vector e(n);

    while (r.max_norm() > eps) {
        e = solveEquations(A_input, r, eps);
        for (long long i = 0; i < n; i++) {
            x[i] += e[i];
        }
        r = residual_vector(A_input, b_input, x);
    }

    return x;
}
