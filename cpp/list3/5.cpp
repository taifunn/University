#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <random>
#include <ctime>
#include <iomanip>
using namespace std;

vector<vector<double>> fill(int s, mt19937_64& rng){
    vector<vector<double>> M(s, vector<double>(s));
    uniform_real_distribution<double> val(0.5, 2.0);
    for(int i=0; i<s; i++){
        for(int j=0; j<s; j++){
            M[i][j] = val(rng);
        }
    }
    return M;
}

vector<vector<double>> matmult(vector<vector<double>> &A, vector<vector<double>> &B){
    int s = A.size();
    vector<vector<double>> C(s, vector<double>(s, 0.0));
    for(int i=0; i<s; i++){
        for(int j=0; j<s; j++){
            double aij = A[i][j];
            for(int k=0; k<s; k++){
                C[i][k] += aij * B[j][k];
        }
    }
    }
    return C;
}

int main() {
    cout.setf(ios::fixed);

    mt19937_64 rng{ std::random_device{}() };
    const int Ns[3]   = {50, 100, 200};
    const int Reps[3] = {200,  60,  12};

    for (int t = 0; t < 3; ++t) {
        int n    = Ns[t];
        int reps = Reps[t];

        auto A = fill(n, rng);

        auto t0 = chrono::high_resolution_clock::now();
        for (int r = 0; r < reps; ++r) {
            auto C = matmult(A, A);
        }
        auto t1 = chrono::high_resolution_clock::now();

        long long ns_total = chrono::duration_cast<chrono::nanoseconds>(t1 - t0).count();
        double ns_avg = double(ns_total) / reps;
        int    ms_avg  = int(ns_avg / 1e6);
        double min_avg =  ns_avg / 60e9;

        cout << "n=" << setw(4) << n
             << "  reps=" << setw(3) << reps
             << "  t_ms(avg)=" << ms_avg
             << "  t_min(avg)=" << setprecision(3) << min_avg
             << "\n";
    }
}