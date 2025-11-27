#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<string> generate_permutations(string s) {
    vector<string> result;

    sort(s.begin(), s.end());

    result.push_back(s);

    while (next_permutation(s.begin(), s.end())) {
        result.push_back(s);
    }

    return result;
}

int main() {
    string word;
    cout << "Podaj slowo: ";
    cin >> word; 

    vector<string> perms = generate_permutations(word);

    cout << "Permutacje:\n";
    for (const auto& p : perms) {
        cout << p << '\n';
    }

    return 0;
}
