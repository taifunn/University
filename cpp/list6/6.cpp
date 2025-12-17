#include <iostream>
#include <string>
#include <tuple>
#include <iomanip>
#include <utility> 
using namespace std;

class person {
public:
    string first_name;
    string last_name;
    int age;
    int weight;
    double height;

    person(const string& fn, const string& ln, int a, int w, double h)
        : first_name(fn), last_name(ln), age(a), weight(w), height(h) {}

    double bmi() const {
        return weight / (height * height);
    }
};

tuple<string, int, double> initials_age_bmi(const person& p) {
    string initials;

    if (!p.first_name.empty()) {
        initials.push_back(p.first_name[0]);
        initials.push_back('.'); 
    }
    if (!p.last_name.empty()) {
        initials.push_back(p.last_name[0]);
        initials.push_back('.');
    }

    return {initials, p.age, p.bmi()};
}

tuple<int, int, double> age_weight_height(const person& p) {
    return {p.age, p.weight, p.height};
}

tuple<string, string, int> name_surname_age(const person& p) {
    return {p.first_name, p.last_name, p.age};
}

int main() {
    person p("Jan", "Kowalski", 30, 82, 1.80);

    auto [initials, age, bmi] = initials_age_bmi(p);

    cout << "Pierwsza funkcja (inicjaly, wiek, BMI):\n";
    cout << "Inicjaly: " << initials << "\n";
    cout << "Wiek:     " << age << "\n";
    cout << fixed << setprecision(2);
    cout << "BMI:      " << bmi << "\n\n";

    auto t2 = age_weight_height(p);
    cout << "Druga funkcja (wiek, waga, wzrost):\n";
    cout << "Wiek:   " << get<0>(t2) << "\n";
    cout << "Waga:   " << get<1>(t2) << " kg\n";
    cout << "Wzrost: " << get<2>(t2) << " m\n\n";

    auto t3 = name_surname_age(p);
    cout << "Trzecia funkcja (imie, nazwisko, wiek):\n";
    cout << "Imie:     " << get<0>(t3) << "\n";
    cout << "Nazwisko: " << get<1>(t3) << "\n";
    cout << "Wiek:     " << get<2>(t3) << "\n";


    return 0;
}