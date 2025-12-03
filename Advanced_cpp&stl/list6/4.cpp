#include <iostream>
#include <fstream>
#include <iterator>
#include <array>
#include <cctype>
#include <iomanip> 
using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Uzycie: " << argv[0] << " nazwa_pliku\n";
        return 1;
    }

    ifstream file(argv[1]);
    if (!file) {
        cerr << "Nie mozna otworzyc pliku: " << argv[1] << "\n";
        return 1;
    }

    int counts[26] = {0};
    int total_letters = 0;

    istreambuf_iterator<char> it(file);
    istreambuf_iterator<char> end;

    while(it != end) {
        char ch = *it;

        if (isalpha(ch)) {
            ch = toupper(ch);

            if (ch >= 'A' && ch <= 'Z') {
                counts[ch - 'A']++;
                total_letters++;
            }
        }
        it++;
    }

    if (total_letters == 0) {
        cout << "Brak liter w tekscie.\n";
        return 0;
    }

    cout << "Czestosc liter:\n\n";
    for (int i = 0; i < 26; ++i) {
        char letter = 'A' + i;
        double freq = static_cast<double>(counts[i]) / static_cast<double>(total_letters);

        int stars = static_cast<int>(freq * 50.0 + 0.5);

        cout << letter << " : "
                  << fixed << setprecision(4) << freq
                  << "  (" << counts[i] << ")\t";

        for (int s = 0; s < stars; s++) {
            cout << '*';
        }
        cout << '\n';
    }

    return 0;
}
