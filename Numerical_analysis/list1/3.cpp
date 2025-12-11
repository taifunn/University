#include <iostream>
#include <cmath>
#include <iomanip>                                                                                          
using namespace std;
#define F float
#define D double

F fun_f(F x){
    return F(162)*((F(1)-cos(F(5)*x))/(x*x));
}
D fun_d(D x){
    return D(162)*((D(1)-cos(D(5)*x))/(x*x));
}
int main(){
    cout << fixed << setprecision(50);
    for(int i=11; i<=20; i++){
        D x = pow(10.0, -i);
        D val_d = fun_d(x);
        F val_f = fun_f(x);
        cout << "f(" << x << ") = " << val_f << " " << val_d << "\n";
    }
}