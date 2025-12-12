#include <utility>
#include <iostream>
#include <vector>
using namespace std;

auto sum = []<typename T>(const auto& tab) -> T {
    T s = 0;
    for (const auto& x : tab) s += x;
    return s;
};

int main(){
    vector<int> A = {1, 2, 3, 4, 5}; //15
    vector<double> B = {1.5, 2.5, 3.5}; //7.5

    cout << "sum<int>(A) = " << sum.template operator()<int>(A) << "\n";
    cout << "sum<double>(B) = " << sum.template operator()<double>(B) << "\n";
    return 0;
}