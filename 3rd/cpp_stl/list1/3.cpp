#include <iostream>
#include <string>
#include <cstdint>
using namespace std;

enum Name : uint16_t{
    Julia,
    Anna,
    Kacper,
    Maciej,
    Piotr
};

void send_message(const string& message, Name receiver){
    cout << "Wiadomość dla ";
    switch(receiver){

        case Name::Julia:
            cout << "Julii: ";
            break;
        case Name::Anna:
            cout << "Anny: ";
            break;
        case Name::Kacper:
            cout << "Kacpra: ";
            break;
        case Name::Maciej:
            cout << "Macieja: ";
            break;
        case Name::Piotr:
            cout << "Piotra: ";
            break;

    }
    cout << message << '\n';
}

int main(){
    send_message("Dzień dobry", Name::Kacper);
    send_message("Gdzie jesteś", Name::Julia);

    return 0;
}
