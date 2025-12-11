#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

double f(double x) {
    return 3.0*x*x - 5.0*cos(7.0*x - 1.0);
}

double bisect(double a, double b, double tol) {
    double fa = f(a), fb = f(b);
    while ((b - a) > 2*tol) {
        double m = 0.5*(a + b);
        double fm = f(m);
        if (fm == 0.0) return m;
        if (fa * fm <= 0.0) { b = m; fb = fm; }
        else               { a = m; fa = fm; }
    }
    return 0.5*(a + b);
}

int main() {
    double L = -3;
    double R =  3;
    double step = 0.001;
    double tol  = 1e-6;

    vector<double> roots;

    double x0 = L;
    double f0 = f(x0);

    for (double x = L + step; x <= R; x += step) {
        double f1 = f(x);

        if (f0 * f1 < 0.0) {
            double r = bisect(x0, x, tol);
            if (roots.empty() || fabs(r - roots.back()) > 1e-6)
                roots.push_back(r);
        }
        x0 = x;
        f0 = f1;
    }

    cout.setf(ios::fixed);
    cout << setprecision(10);
    for (double r : roots) cout << r << "\n";
    return 0;
}
