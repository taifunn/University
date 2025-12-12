#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
using namespace std;

class osoba {
    string nazwisko;
    string imie;
    int rok_uro;

public:
    osoba(string n, string i, int r)
        : nazwisko(n), imie(i), rok_uro(r) {}

    void show() const {
        cout << nazwisko << " " << imie << " " << rok_uro << "\n";
    }

    friend bool operator<(const osoba& os1, const osoba& os2) {
        return tie(os1.nazwisko, os1.imie, os1.rok_uro)
             < tie(os2.nazwisko, os2.imie, os2.rok_uro);
    }
};

int main() {
    vector<osoba> osoby = {
        {"Pająk", "Ania", 1990},
        {"Białko", "Weronika", 2002},
        {"Konek", "Patrycja", 1996},
        {"Pieczarek", "Marek", 1980},
        {"Palub", "Wiktoria", 2009},
    };

    cout << "\nprzed posortowaniem:\n\n";
    for (const auto& o : osoby)
        o.show();

    sort(osoby.begin(), osoby.end());

    cout << "\npo posortowaniu:\n\n";
    for (const auto& o : osoby)
        o.show();

    return 0;
}
