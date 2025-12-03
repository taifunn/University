#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    cout.setf(ios::fixed); 

    vector<double> Id(21);
    vector<float>  If(21);  
    Id[0] = log(2026.0/2025.0); 
    If[0] = (float)log(2026.0/2025.0);

    for (int n = 1; n <= 20; n++) {
        Id[n] = 1.0/n - 2025.0 * Id[n-1];
        If[n] = (float)(1.0/n) - 2025.0f * If[n-1];
    }

    cout << setprecision(10);

    cout << "DOUBLE (I1..I20):\n";
    for (int n = 1; n <= 20; ++n) cout << "I" << n << " = " << Id[n] << "\n";

    cout << "\nFLOAT (I1..I20):\n";
    for (int n = 1; n <= 20; ++n) cout << "I" << n << " = " << If[n] << "\n";

    cout << "\nDOUBLE nieparzyste (I1,I3,...,I19):\n";
    for (int n = 1; n <= 19; n += 2) cout << "I" << n << " = " << Id[n] << "\n";

    cout << "\nDOUBLE parzyste (I2,I4,...,I20):\n";
    for (int n = 2; n <= 20; n += 2) cout << "I" << n << " = " << Id[n] << "\n";

    cout << "\nFLOAT nieparzyste (I1,I3,...,I19):\n";
    for (int n = 1; n <= 19; n += 2) cout << "I" << n << " = " << If[n] << "\n";

    cout << "\nFLOAT parzyste (I2,I4,...,I20):\n";
    for (int n = 2; n <= 20; n += 2) cout << "I" << n << " = " << If[n] << "\n";
}
