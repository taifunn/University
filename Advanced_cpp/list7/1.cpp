#include <iostream>
#include <complex>
#include <cmath>

using namespace std;
using cd = complex<double>;

const double euler_gamma = 0.5772156649;

cd gamma_euler(cd z, int N){
    cd prod(1.0, 0.0);

    for(int n=1; n<=N; n++){
        cd n_c(n, 0.0);
        prod *= exp(z/n_c)/(cd(1.0, 0.0) + z/n_c);
    }
    return exp(-euler_gamma * z) / z * prod;
}

cd inv_gamma_euler(cd z, int N){
    cd prod(1.0, 0.0);
    for(int n=1; n<=N; n++){
        cd n_c(n, 0.0);
        prod *= (cd(1.0, 0.0) + z/n_c) * exp(-z/n_c);
    }
    return z * exp(euler_gamma * z) * prod;
}

int main(){
    const int N = 100000;

    for(int i=1; i<=10; i++){
        cd z(i, 0.0);
        cd gamma_val = gamma_euler(z, N);
        cd inv_gamma_val = inv_gamma_euler(z, N);
        cout << "z: " << z << "\n";
        cout << "Gamma(z): " << gamma_val << "\n";
        cout << "1/Gamma(z): " << inv_gamma_val << "\n";
        cout << "iloczyn: " << gamma_val * inv_gamma_val << "\n\n";
    }
}