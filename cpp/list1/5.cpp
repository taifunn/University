#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double a, b, c;
    cin >> a >> b >> c;

    if(double delta = (b * b) - (4 * a * c); delta > 0){
        double x1 = (-b - sqrt(delta)) / (2*a);
        double x2 = (-b + sqrt(delta)) / (2*a);

        cout << "Pierwiastki: " << x1 << ", " << x2 << "/n";
    }
    else if(double delta = (b * b) - (4 * a * c); delta == 0){
        double x1 = -b / (2*a);
        cout << "Jeden pierwiastek: " << x1 << "/n";
    }
    else{
        cout << "Brak pierwiastkow w R\n";
    }
    return 0;
}