#include <climits>
#include <iostream>
using namespace std;
int main(){
    cout << "min =" << std::numeric_limits<long double>::min() << "\n";
    cout << "min subnormalne = " << numeric_limits<long double>::denorm_min() << "\n";
    cout << "max = " << numeric_limits<long double>::max() << "\n";
    cout << "nieskonczonosc? " << numeric_limits<long double>::has_infinity << "\n";
    cout << "nieskonczonosc: = " << numeric_limits<long double>::infinity() << "\n";
    cout << "epsilon = " << numeric_limits<long double>::epsilon() << "\n";
}
