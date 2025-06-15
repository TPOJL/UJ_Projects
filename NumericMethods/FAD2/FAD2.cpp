#include <iostream>
#include <cmath>
#include <iomanip>
#include "funkcja.h"
using namespace std;

class Dzet {
public:
    double val, dx, dy, dxx, dxy, dyy;

    Dzet() : val(0.0), dx(0.0), dy(0.0), dxx(0.0), dxy(0.0), dyy(0.0) {}

    Dzet(double v, double dx_, double dy_, double dxx_, double dxy_, double dyy_)
            : val(v), dx(dx_), dy(dy_), dxx(dxx_), dxy(dxy_), dyy(dyy_) {}

    Dzet& operator=(const Dzet &other) {
        if (this != &other) {
            val = other.val;
            dx = other.dx;
            dy = other.dy;
            dxx = other.dxx;
            dxy = other.dxy;
            dyy = other.dyy;
        }
        return *this;
    }

    Dzet operator+(const Dzet &b) const {
        return Dzet(val + b.val, dx + b.dx, dy + b.dy, dxx + b.dxx, dxy + b.dxy, dyy + b.dyy);
    }

    Dzet operator-(const Dzet &b) const {
        return Dzet(val - b.val, dx - b.dx, dy - b.dy, dxx - b.dxx, dxy - b.dxy, dyy - b.dyy);
    }

    Dzet operator*(const Dzet &b) const {
        return Dzet(
                val * b.val,
                dx * b.val + val * b.dx,
                dy * b.val + val * b.dy,
                dxx * b.val + 2 * dx * b.dx + val * b.dxx,
                dxy * b.val + dx * b.dy + dy * b.dx + val * b.dxy,
                dyy * b.val + 2 * dy * b.dy + val * b.dyy
        );
    }

    Dzet operator/(const Dzet &b) const {
        double v = b.val;
        double v2 = v * v;
        double v3 = v2 * v;
        return Dzet(
                val / v,
                (dx * v - val * b.dx) / v2,
                (dy * v - val * b.dy) / v2,
                (dxx * v2 - 2 * dx * b.dx * v + 2 * val * b.dx * b.dx - val * v * b.dxx) / v3,
                (dxy * v2 - dx * b.dy * v - dy * b.dx * v + 2 * val * b.dx * b.dy - val * v * b.dxy) / v3,
                (dyy * v2 - 2 * dy * b.dy * v + 2 * val * b.dy * b.dy - val * v * b.dyy) / v3
        );
    }

    Dzet operator-() const {
        return Dzet(-val, -dx, -dy, -dxx, -dxy, -dyy);
    }
    
    Dzet operator+(double c) const { return Dzet(val + c, dx, dy, dxx, dxy, dyy); }
    Dzet operator-(double c) const { return Dzet(val - c, dx, dy, dxx, dxy, dyy); }
    Dzet operator*(double c) const { return Dzet(val * c, dx * c, dy * c, dxx * c, dxy * c, dyy * c); }
    Dzet operator/(double c) const { return Dzet(val / c, dx / c, dy / c, dxx / c, dxy / c, dyy / c); }
};
Dzet operator+(double c, const Dzet &z) { return z + c; }
Dzet operator-(double c, const Dzet &z) { return Dzet(c - z.val, -z.dx, -z.dy, -z.dxx, -z.dxy, -z.dyy); }
Dzet operator*(double c, const Dzet &z) { return z * c; }
Dzet operator/(double c, const Dzet &z) {
    double v2 = z.val * z.val;
    double v3 = v2 * z.val;
    return Dzet(
            c / z.val,
            -c * z.dx / v2,
            -c * z.dy / v2,
            (2 * c * z.dx * z.dx - c * z.val * z.dxx) / v3,
            (2 * c * z.dx * z.dy - c * z.val * z.dxy) / v3,
            (2 * c * z.dy * z.dy - c * z.val * z.dyy) / v3
    );
}

Dzet sin(const Dzet &z) {
    double s = sin(z.val);
    double c = cos(z.val);
    return Dzet(
            s,
            c * z.dx,
            c * z.dy,
            -s * z.dx * z.dx + c * z.dxx,
            -s * z.dx * z.dy + c * z.dxy,
            -s * z.dy * z.dy + c * z.dyy
    );
}

Dzet cos(const Dzet &z) {
    double s = sin(z.val);
    double c = cos(z.val);
    return Dzet(
            c,
            -s * z.dx,
            -s * z.dy,
            -c * z.dx * z.dx - s * z.dxx,
            -c * z.dx * z.dy - s * z.dxy,
            -c * z.dy * z.dy - s * z.dyy
    );
}

Dzet exp(const Dzet &z) {
    double e = exp(z.val);
    return Dzet(
            e,
            e * z.dx,
            e * z.dy,
            e * (z.dxx + z.dx * z.dx),
            e * (z.dxy + z.dx * z.dy),
            e * (z.dyy + z.dy * z.dy)
    );
}

int main() {
    int M;
    cin >> M;
    cout << setprecision(15) << fixed;
    for (int i = 0; i < M; ++i) {
        double x0, y0;
        cin >> x0 >> y0;
        Dzet x(x0, 1, 0, 0, 0, 0);
        Dzet y(y0, 0, 1, 0, 0, 0);
        Dzet r = funkcja(x, y);
        cout << r.val << " " << r.dx << " " << r.dy << " " << r.dxx << " " << r.dxy << " " << r.dyy << endl;
    }
    return 0;
}
