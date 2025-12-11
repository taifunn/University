#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    cout.setf(ios::fixed); cout << setprecision(6);

    auto f = [](double x){ return x - 0.49; };
    const double a0 = 0.0, b0 = 1.0, alpha = 0.49;
    int N = 5;

    double a = a0, b = b0;

    cout << " n |      a_n |      b_n |       c_n |    f(c_n) |   |e_n|   |  bound 1/2^n\n";
    cout << "-----------------------------------------------------------------------------\n";

    for (int n = 1; n <= N; ++n) {
        double c = 0.5 * (a + b);
        double fc = f(c);
        double en = fabs(c - alpha); //blad
        double bound = pow(0.5, n); //oszacowanie 

        cout << setw(2) << n << " | "
             << setw(8) << a << " | "
             << setw(8) << b << " | "
             << setw(8) << c << " | "
             << setw(9) << fc << " | "
             << setw(8) << en << " | "
             << setw(10) << bound << "\n";

        if ((f(a) <= 0 && fc >= 0) || (f(a) >= 0 && fc <= 0)) {
            b = c; // zero w [a,c]
        } else {
            a = c; // zero w [c,b]
        }
    }
    return 0;
}
