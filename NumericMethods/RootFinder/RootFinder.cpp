#include <cmath>
using namespace std;

double findZero(
        double (*f)(double),
        double a, double b,
        int M,
        double eps,
        double delta
) {
    double fa = f(a);
    double fb = f(b);
    M -= 2;

    bool mix = (fa * fb <= 0);
    double x = a, fx;

    if (mix) {
        int k = M / 2;
        for (int i = 0; i < k && M > 0; ++i) {
            x = 0.5 * (a + b);
            fx = f(x);
            --M;
            if (abs(fx) <= eps) return x;
            if (abs(b - a) <= delta) return x;
            if (fa * fx <= 0) {
                b = x; fb = fx;
            } else {
                a = x; fa = fx;
            }
        }
        double x0 = a, f0 = fa;
        double x1 = b, f1 = fb;
        while (M > 0) {
            if (f1 == f0) break;
            x = x1 - f1 * (x1 - x0) / (f1 - f0);
            fx = f(x);
            --M;
            if (abs(fx) <= eps) return x;
            x0 = x1; f0 = f1;
            x1 = x;  f1 = fx;
        }
    } else {
        double x0 = a, f0 = fa;
        double x1 = b, f1 = fb;
        while (M > 0) {
            if (f1 == f0) break;
            x = x1 - f1 * (x1 - x0) / (f1 - f0);
            fx = f(x);
            --M;
            if (abs(fx) <= eps) return x;
            x0 = x1; f0 = f1;
            x1 = x;  f1 = fx;
        }
    }
    return x;
}
