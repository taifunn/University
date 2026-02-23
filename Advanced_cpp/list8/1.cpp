#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main(){
    regex time(R"(^([01][0-9]|2[0-3]):[0-5][0-9](:[0-5][0-9])?$)");

    string line;
    cout << "Podaj godzine" << "\n";
    while(getline(cin, line)){
        if(regex_match(line, time)){
            cout << "Poprawna godzina\n";
        } else {
            cout << "Niepoprawna godzina\n";
        }
    }
}