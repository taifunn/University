#include <iostream>
#include <vector>
#include <compare>
using namespace std;

pair<vector<int>::iterator, vector<int>::iterator>
find(vector<int>& v, int x) {
    auto l = v.begin();
    auto r = v.end();

    while (l < r) {
        auto mid = l + (r - l) / 2;
        auto comp = (*mid <=> x);
        if (comp < 0)
            l = mid + 1;
        else
            r = mid;
    }
    auto low = l;

    l = low;
    r = v.end();
    while (l < r) {
        auto mid = l + (r - l) / 2;
        auto comp = (*mid <=> x);
        if (comp <= 0) 
            l = mid + 1;
        else            
            r = mid;
    }
    auto high = l;

    return {low, high};
}

int main() {
    vector<int> v = {1, 2, 3, 3, 4, 5, 5, 5, 6, 7, 7, 7, 7, 8, 9};

    int x;
    cout << "Podaj szukana wartosc: ";
    cin >> x;

    auto [beg, end] = find(v, x);

    if (beg == end) {
        cout << "Brak elementu " << x << " w wektorze.\n";
    } else {
        cout << "Element " << x << " wystepuje " << distance(beg, end)
             << " razy, na pozycjach: ";
        for (auto it = beg; it != end; ++it)
            cout << (it - v.begin()) << " ";
        cout << "\n";
    }
}
