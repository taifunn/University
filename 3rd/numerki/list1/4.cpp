#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
#define f float

f y(int n){
    if(n == 0) return 1.0;
    if(n == 1) return -1.0/9.0;
    return (98.0/9.0)*y(n-1) + (11.0/9.0)*y(n-2);
}

f alt_y(int n){ //poprawne wyniki z wyprowadzonego wzoru 
    return pow((-1.0/9.0), n);
}
int main(){
    cout << setprecision(50)<<fixed;

    for(int i=2; i<=50; i++){
        cout << i << y(i) << " " << alt_y(i) << '\n';
    }
    return 0;
}