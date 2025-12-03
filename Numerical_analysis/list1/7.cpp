#include <iostream>
#include <iomanip>
#include <cmath>  
using namespace std;

double cos_alt(double x, double e = 1e-15) {

    double t = 1.0; 
    double s = 1.0; 
    int k = 0;

    const double x2 = x * x;

    while(true){
        double den = ((2 * k) + 1) * ((2 * k) + 2);
        t = (-t) * (x2 / den);
        s += t;
        if(abs(t) < e) break;
        k++;
    }
    return s;
}

int main() {
    cout << setprecision(17)<<fixed;

    const double PI = 3.14159265358979323846;
    double xs[] = { -PI, -PI/2, -1.0, 0.0, 1.0, PI/3, PI/2, PI };

    for (double x : xs) {
        double v = cos_alt(x, 1e-15);
        double ref = cos(x);
        double err = abs(v - ref);
        cout << "wartosc: " << x << "\n"
        << "moja funkcja: " << v << "\n"
        << "wbudowana funkcja: " << ref << "\n"
        << "roznica: " << err << "\n";
    }
    return 0;
}
