#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
#include <iomanip>
using namespace std;

class person {
public:
    string first_name;
    string last_name;
    int age;        // lata
    int weight;     // kg
    double height;  // m

    person(const string& fn,
           const string& ln,
           int a,
           int w,
           double h)
        : first_name(fn), last_name(ln), age(a), weight(w), height(h) {}

    double bmi() const {
        return weight / (height * height);
    }
};

ostream& operator<<(ostream& os, const person& p) {
    os << p.first_name << " " << p.last_name
       << ", wiek: " << p.age
       << ", waga: " << p.weight << " kg"
       << ", wzrost: " << p.height << " m"
       << ", BMI: " << fixed << setprecision(2) << p.bmi();
    return os;
}

// wypisanie całej kolekcji
void print_group(const deque<person>& people, const string& title) {
    cout << "=== " << title << " ===\n";
    for (const auto& p : people) {
        cout << p << "\n";
    }
    cout << "\n";
}

int main() {
    deque<person> people = {
        {"Jan",    "Kowalski",   30,  80, 1.80},
        {"Anna",   "Nowak",      25,  60, 1.65},
        {"Piotr",  "Zielinski",  45, 110, 1.75},
        {"Kasia",  "Wesola",     19,  55, 1.70},
        {"Tomek",  "Lis",        50, 120, 1.82},
        {"Ola",    "Krawczyk",   35,  68, 1.60},
        {"Marek",  "Zawada",     40,  95, 1.90},
        {"Ewa",    "Cicha",      28,  72, 1.68},
        {"Adam",   "Zuk",        60,  85, 1.72},
        {"Magda",  "Bogata",     33, 105, 1.75},
        {"Bartek", "Nowy",       22,  78, 1.79},
        {"Iza",    "Smutna",     27,  52, 1.58}
    };

    sort(people.begin(), people.end(),
              [](const person& a, const person& b) {
                  return a.bmi() < b.bmi();
              });

    print_group(people, "a) Posortowane wedlug BMI");

    for_each(people.begin(), people.end(),
                  [](person& p) {
                      p.weight = static_cast<int>(p.weight * 0.9);
                  });

    print_group(people, "b) Po odchudzeniu (10% mniej wagi)");

    // c) podział na ciężkich (>100 kg) i lekkich (<= 100 kg)
    // użyjemy stable_partition z lambdą jako predykatem
    auto it_first_light = stable_partition(
        people.begin(), people.end(),
        [](const person& p) {
            return p.weight > 100;  // TRUE -> ciężcy na początku
        });

    deque<person> heavy(people.begin(), it_first_light);
    deque<person> light(it_first_light, people.end());

    print_group(heavy, "c) Grupa ciezka (waga > 100 kg)");
    print_group(light, "c) Grupa lekka (waga <= 100 kg)");

    // d) osoba najstarsza i najmłodsza (bez sortowania)
    auto [it_min_age, it_max_age] = minmax_element(
        people.begin(), people.end(),
        [](const person& a, const person& b) {
            return a.age < b.age;
        });

    cout << "d) Najmlodsza osoba:\n";
    cout << *it_min_age << "\n\n";

    cout << "d) Najstarsza osoba:\n";
    cout << *it_max_age << "\n";

    return 0;
}
