#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

vector<double> SOR(const vector<vector<double>>& lines, const vector<double>& diag, const vector<double>& b, const vector<double>& _x0, long M, double w, long iterations) {
    vector<double> x = _x0;
    long N = diag.size();

    for (long it = 0; it < iterations; ++it) {
        for (long i = 0; i < N; ++i) {
            double sum = b[i];
            for (long m = 1; m <= M; ++m) {
                if (i - m >= 0) {
                    sum -= lines[M - m][i - m] * x[i - m];
                }
            }
            for (long m = 1; m <= M; ++m) {
                if (i + m < N) {
                    sum -= lines[M - m][i] * x[i + m];
                }
            }
            x[i] = (1 - w) * x[i] + w * sum / diag[i];
        }
    }

    return x;
}

int main() {
    long N, M;
    cin >> N >> M;

    vector<vector<double>> lines(M);
    for (long k = 0; k < M; ++k) {
        long len = N - (M - k);
        lines[k].resize(len);
        for (long i = 0; i < len; ++i) {
            cin >> lines[k][i];
        }
    }

    vector<double> diag(N), b(N), x0(N);
    for (double& val : diag) cin >> val;
    for (double& val : b) cin >> val;
    for (double& val : x0) cin >> val;

    double w;
    long L;
    cin >> w >> L;

    vector<double> x = SOR(lines, diag, b, x0, M, w, L);

    cout << scientific << setprecision(16);
    for (double val : x) {
        cout << val << endl;
    }

    return 0;
}
