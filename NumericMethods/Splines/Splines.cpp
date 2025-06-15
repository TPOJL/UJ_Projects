#include <vector>
#include "source.h"
using namespace std;

spline::spline(int n) : n(n) {
    x = new double[n];
    y = new double[n];
    a = new double[n];
    b = new double[n];
    c = new double[n];
    d = new double[n];
}

void spline::set_points(double x_input[], double y_input[]) {
    for (int i = 0; i < n; ++i) {
        x[i] = x_input[i];
        a[i] = y_input[i];
    }

    vector<double> h(n);
    for (int i = 1; i < n; ++i) {
        h[i] = x[i] - x[i - 1];
    }

    vector<double> right(n);
    for (int i = 1; i < n - 1; ++i) {
        right[i] = 3.0 * (((a[i + 1] - a[i]) / h[i + 1]) - (a[i] - a[i - 1]) / h[i]);
    }

    vector<double> mid(n), C(n);
    mid[0] = 0.0;
    C[0] = 0.0;
    for (int i = 1; i < n - 1; ++i) {
        double second = 2.0 * (h[i] + h[i + 1]) - h[i] * mid[i - 1];
        mid[i] = h[i + 1] / second;
        C[i] = (right[i] - (h[i] * C[i - 1])) / second;
    }

    C[n - 1] = 0.0;
    c[n - 1] = 0.0;
    for (int i = n - 2; i >= 0; --i) {
        c[i] = C[i] - (mid[i] * c[i + 1]);
        b[i] = ((a[i + 1] - a[i]) / h[i + 1]) - ((h[i + 1] * (2.0 * c[i] + c[i + 1])) / 3.0);
        d[i] = (c[i + 1] - c[i]) / (3.0 * h[i + 1]);
    }
}

double spline::operator()(double z) const {
    if (z <= x[0]) {
        double D = z - x[0];
        return a[0] + b[0] * D + c[0] * D * D + d[0] * D * D * D;
    }
    if (z >= x[n - 1]) {
        double D = z - x[n - 2];
        return a[n - 2] + b[n - 2] * D + c[n - 2] * D * D + d[n - 2] * D * D * D;
    }
    int j = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (z < x[i + 1]) {
            j = i;
            break;
        }
    }
    double D = z - x[j];
    return a[j] + b[j] * D + c[j] * D * D + d[j] * D * D * D;
}
