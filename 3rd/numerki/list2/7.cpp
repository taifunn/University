#include <iostream>
#include <cmath>
#include <iomanip>   
#define d double
using namespace std;

d f(d x){
    return (sqrt(pow(x, 15) * 12150 + 9) - 3) / pow(x,15);
}

d f_snd(d x){
    return 12150 / (sqrt(12150 * pow(x,15) + 9) + 3);
}

int main(){
    cout<<setprecision(20)<<fixed;
    cout << f(0.01) << "\n" << f_snd(0.01);
}