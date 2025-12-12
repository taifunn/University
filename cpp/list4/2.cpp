#include <utility>
#include <iostream>

template<class F, class G>
auto po_kolei(F f, G g) {
    return [f, g](auto &&... args){
        f(args...);
        g(args...);
    };
};

void f1(int& x) { std::cout << "f1\n"; x += 1; }    
int  f2(int& x) { std::cout << "f2\n"; x *= 2; return 42; } 
double f3(int& x) { std::cout << "f3\n"; x -= 3; return 3.14; }

int main(){
    int a = 10;

    auto h = po_kolei(po_kolei(f1, f2), f3);
    h(a);

    std::cout << "a = " << a << "\n";

    auto log = [](int){ std::cout << "tiriri\n"; };
    auto all = po_kolei(h, log); 
    all(a);

    return 0;
}