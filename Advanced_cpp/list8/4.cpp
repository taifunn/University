#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main(){
    regex complex(R"(^\(-?\d+(?:\.\d+)?[+-]\d+(?:\.\d+)?[iI]\)$)");
    string line;
    cout << "Podaj liczbe zespolona" << "\n";
    while(getline(cin, line)){
        if(regex_match(line, complex)){
            cout << "Poprawna liczba zespolona\n";
        } else {
            cout << "Niepoprawna liczba zespolona\n";
        }
    }
}