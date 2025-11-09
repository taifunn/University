#include <iostream>
#include <cmath>

int iters(double R, double x0, double tol = 1e-15, int max_it = 200) {
    double x = x0;
    for (int k = 1; k <= max_it; ++k) {
        x = x * (2.0 - R * x);          
        if (std::fabs(1.0 - R * x) < tol) 
            return k;
    }
    return -1;
}

int main() {
    const double Rs[]  = {1e-6, 1e-3, 0.1, 1.0, 2.0, 10.0, 1e6};
    const double X0s[] = {1e-6, 1e-3, 1e-1, 0.5, 1.0};

    long long total = 0;
    int count = 0;

    std::cout << "R\t\tx0\t\titeracje\n";
    for (double R : Rs) {
        for (double x0 : X0s) {
            int k = iters(R, x0);
            std::cout << R << "\t" << x0 << "\t" << k << "\n";
            if (k >= 0) { total += k; ++count; }
        } // 0 < x0 <2/R 
    }

    if (count > 0) {
        std::cout << "\nSrednia liczba iteracji: "
                  << (double)total / (double)count
                  << " (po " << count << " przypadkach)\n";
    }
    return 0;
}
