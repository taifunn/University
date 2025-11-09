#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int ite = 0;
double invsqrt(double a) {
    double y = min(1.0/a, 1.0);
    for (int i = 0; i < 50; ++i) {
        y = y * (1.5 - 0.5 * a * y * y);
        ite++;
        if( fabs(y * y - 1.0 / a) < 1e-15) break;
    }
    return y;
}
int main() {
    double A[] = {9, 6.54, 2.4343, 0.001, 0.1, 1.0, 2.0, 123.456, 1e6,};
    for (double a : A) {
        ite = 0;
        double y = invsqrt(a);
        cout << "a=" << a << "  1/sqrt(a) ~ " << y << "\n";
        cout << ite << " iteracji\n";
    }
}
