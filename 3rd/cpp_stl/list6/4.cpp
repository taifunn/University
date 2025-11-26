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

    array<size_t, 26> counts{};
    counts.fill(0);

    size_t total_letters = 0;

    istreambuf_iterator<char> it(file);
    istreambuf_iterator<char> end;

    for (; it != end; ++it) {
        unsigned char ch = static_cast<unsigned char>(*it);

        if (isalpha(ch)) {
            ch = static_cast<unsigned char>(toupper(ch));

            if (ch >= 'A' && ch <= 'Z') {
                counts[ch - 'A']++;
                total_letters++;
            }
        }
    }

    if (total_letters == 0) {
        cout << "Brak liter w tekscie.\n";
        return 0;
    }

    cout << "Histogram czestosci liter (tylko A-Z):\n\n";
    for (int i = 0; i < 26; ++i) {
        char letter = 'A' + i;
        double freq = static_cast<double>(counts[i]) / static_cast<double>(total_letters);

        int stars = static_cast<int>(freq * 50.0 + 0.5);

        cout << letter << " : "
                  << fixed << setprecision(4) << freq
                  << "  (" << counts[i] << ")\t";

        for (int s = 0; s < stars; ++s) {
            cout << '*';
        }
        cout << '\n';
    }

    return 0;
}
