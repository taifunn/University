#include <ratio>
#include <iostream>

template<int N> 
struct H {
    using h_prev = typename H<N - 1>::type;
    using type = std::ratio_add<h_prev, std::ratio<1, N>>;
};

template<> struct H<1> { using type = std::ratio<1,1>; };

int main() {
    using H10 = H<10>::type;
    std::cout << "H10 = " << H10::num << "/" << H10::den << '\n';

    using H46 = H<46>::type;
    std::cout << "H46 = " << H46::num << "/" << H46::den << '\n';
}