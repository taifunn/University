#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main(){
    regex date(R"(^(?:(?:0[1-9]|[12][0-9]|3[01])-(?:0[13578]|1[02])|(?:0[1-9]|[12][0-9]|30)-(?:0[469]|11)|(?:0[1-9]|1[0-9]|2[0-8])-02)-\d{4}$)");
    string line;
    cout << "Podaj date" << "\n";
    while(getline(cin, line)){
        if(regex_match(line, date)){
            cout << "Poprawna data\n";
        } else {
            cout << "Niepoprawna data\n";
        }
    }
}