#include <iostream>
#include <limits>
#include <string>

int main() {
    using ll = long long;

    std::cout << "min long long = " << std::numeric_limits<ll>::min() << '\n';
    std::cout << "max long long = " << std::numeric_limits<ll>::max() << '\n';

    std::cout << "znak? "
              << (std::numeric_limits<ll>::is_signed ? "tak" : "nie") << '\n';

    std::cout << "liczba bitow: " << sizeof(ll) * 8 << '\n';

    std::string s = std::to_string(std::numeric_limits<ll>::max());
    std::cout << "max cyfr dziesietnych: " << s.size() << '\n';

    return 0;
}
