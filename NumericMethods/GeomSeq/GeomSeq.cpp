#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void SolveGeomSeq(float P, float S) {
    if (P == 0 || S == 0) {
        cout << fixed << setprecision(10) << scientific;
        cout << 0.0 << " " << 0.0 << " " << 0.0 << endl;
        return;
    }
    if (pow(cbrt(P) - S, 2) - 4 * pow(cbrt(P), 2) < 0) {
        cout << fixed << setprecision(10) << scientific;
        cout << 0.0 << " " << 0.0 << " " << 0.0 << endl;
        return;
    }
    float x1, x3;
    if (-cbrt(P) + S < 0) {
        x1 = cbrt(P) * (-cbrt(P) + S - sqrt(pow(cbrt(P) - S, 2) - 4 * pow(cbrt(P), 2))) / (2 * cbrt(P));
        x3 = (cbrt(P) / (cbrt(P) * (-cbrt(P) + S - sqrt(pow(cbrt(P) - S, 2) - 4 * pow(cbrt(P), 2))) / (2 * cbrt(P)))) * cbrt(P);
    } else {
        x1 = cbrt(P) * (-cbrt(P) + S + sqrt(pow(cbrt(P) - S, 2) - 4 * pow(cbrt(P), 2))) / (2 * cbrt(P));
        x3 = (cbrt(P) / (cbrt(P) * (-cbrt(P) + S + sqrt(pow(cbrt(P) - S, 2) - 4 * pow(cbrt(P), 2))) / (2 * cbrt(P)))) * cbrt(P);
    }
    if (x1 < x3) {
        swap(x1, x3);
    }
    cout << fixed << setprecision(10) << scientific;
    cout << x1 << " " << cbrt(P) << " " << x3 << endl;
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        float P, S;
        cin >> P >> S;
        SolveGeomSeq(P, S);
    }
    return 0;
}
