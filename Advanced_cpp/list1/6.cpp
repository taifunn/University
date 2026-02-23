#include <iostream>
using namespace std;

int main() {
    int dzien, miesiac, rok;

    cout << "Podaj date (dzien miesiac rok): ";
    cin >> dzien >> miesiac >> rok;

    switch (auto m = miesiac) {
        case 1:  cout << dzien << " stycznia "   << rok; break;
        case 2:  cout << dzien << " lutego "     << rok; break;
        case 3:  cout << dzien << " marca "      << rok; break;
        case 4:  cout << dzien << " kwietnia "   << rok; break;
        case 5:  cout << dzien << " maja "       << rok; break;
        case 6:  cout << dzien << " czerwca "    << rok; break;
        case 7:  cout << dzien << " lipca "      << rok; break;
        case 8:  cout << dzien << " sierpnia "   << rok; break;
        case 9:  cout << dzien << " września "   << rok; break;
        case 10: cout << dzien << " października " << rok; break;
        case 11: cout << dzien << " listopada "  << rok; break;
        case 12: cout << dzien << " grudnia "    << rok; break;
        default:
            cout << "Niepoprawny numer miesiaca";
            break;
    }

    cout << "\n";
    return 0;
}
