#include <climits>
#include <iostream>
int main() {
    std::cout << "ll min =" << LLONG_MIN << "\n" << "ll max=" << LLONG_MAX << '\n'; //19 cyfr
    std::cout << "bits long long=" << 8*sizeof(long long);
}