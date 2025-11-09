#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <random>
#include <ctime>
#include <iomanip>
using namespace std;

template<typename T>
using fun = T(*)(T);

template<typename T>
void transform(T tab[], int n, fun<T> f){
    for(int i=0; i<n; i++){
        tab[i] = f(tab[i]);
    }
}

int is_even(int x){
    return x % 2 == 0;
}
int square(int x){
    return x * x;
}
int sum1(int x){
    return x + 1;
}


int main(){
    int tab[] = {1, 2, 3, 4, 5};

    cout << "Suma 1 do kazdego el: ";
    transform(tab, 5, sum1);
    cout << "tab: ";
    for(int i=0; i<5; i++){
        cout << tab[i] << " ";
    }
    cout << "\n";

    cout << "Kwadrat: ";
    transform(tab, 5, square);
    cout << "tab: ";
    for(int i=0; i<5; i++){
        cout << tab[i] << " ";
    }
    cout << "\n";

    cout << "Czy parzyste: ";
    transform(tab, 5, is_even);
    cout << "tab: ";
    for(int i=0; i<5; i++){
        cout << tab[i] << " ";
    }

}