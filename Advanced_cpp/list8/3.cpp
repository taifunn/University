#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main(){
    regex city(R"(^[A-Z][a-z]+(?:-[A-Z][a-z]+)*(?:\s+[A-Z][a-z]+(?:-[A-Z][a-z]+)*)*$)");
    string line;
    cout << "Podaj nazwe miejscowości" << "\n";
    while(getline(cin, line)){
        if(regex_match(line, city)){
            cout << "Poprawna nazwa miejscowości\n";
        } else {
            cout << "Niepoprawna nazwa miejscowości\n";
        }
    }
}