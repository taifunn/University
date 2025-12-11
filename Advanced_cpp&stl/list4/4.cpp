#include <utility>
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <string>
#include <functional>
#include <stdexcept>
using namespace std;

int main(){
    function<long long(int,int)> newton;

    newton = [&](int n, int k) -> long long {
        if(n<0 || k<0 || k>n) throw invalid_argument("powinno byc 0<=k<=n");
        if(k==0 || k==n) return 1;

        k = min(k, n - k);
        return newton(n - 1, k - 1) + newton(n - 1, k);
    };

    vector<std::pair<int,int>> tests = {
        {5, 2},   // 10
        {6, 3},   // 20
        {10, 0},  // 1
        {10, 10}, // 1
        {10, 1},  // 10
        {7, -1}   // wyjatek
    };

    for (auto [n, k] : tests) {
        try {
            std::cout << "C(" << n << "," << k << ") = "
                      << newton(n, k) << "\n";
        } catch (const std::exception& e) {
            std::cout << "C(" << n << "," << k << ") -> wyjatek: "
                      << e.what() << "\n";
        }
    }

}