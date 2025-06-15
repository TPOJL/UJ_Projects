#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

static long double factorial(int j){
    long double f = 1.0;
    for (int t = 1; t <= j; ++t) f *= t;
    return f;
}

static void INTERPOLATE(int M, int N, long double X[], long double Y[], long double T[]) {
    long double A[M][M], W[M], F[M];
    for (int i = 0; i < M; ++i) {
        if (i > 0 && X[i] == X[i - 1])
            A[i][0] = A[i - 1][0];
        else
            A[i][0] = Y[i];

        for (int j = 1; j <= i; ++j) {
            if (fabs(X[i] - X[i - j]) < 1e-10)
                A[i][j] = Y[i] / factorial(j);
            else
                A[i][j] = (A[i][j - 1] - A[i - 1][j - 1]) / (X[i] - X[i - j]);
        }
    }

    ///a[k]
    for (int k = 0; k < M; ++k) {
        W[k] = A[k][k];
        cout << fixed << setprecision(17) << W[k] << " ";
    }
    cout << endl;
    ///F[i]
    for (int i = 0; i < N; ++i) {
        long double val = 0;
        for (int k = 0; k < M; ++k) {
            long double prod = 1.0;
            for (int j = 0; j < k; ++j) {
                prod *= (T[i] - X[j]);
            }
            val += W[k] * prod;
        }
        cout << fixed << setprecision(17) << val << " ";
    }
}

int main() {
    int M, N;
    cin >> M >> N;
    long double X[M], Y[M], T[N];
    for (int i = 0; i < M; ++i) {
        cin >> X[i];
    }
    for (int i = 0; i < M; ++i) {
        cin >> Y[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> T[i];
    }

    INTERPOLATE(M, N, X, Y, T);
    return 0;
}
