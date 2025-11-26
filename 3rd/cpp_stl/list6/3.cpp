#include <vector>
#include <unordered_map>
#include <utility>  
#include <iostream> 
using namespace std;

vector<pair<int, int>>
most_frequent(const vector<int> &data) {
    unordered_map<int, int> counts;

    for (int x : data) {
        counts[x]++;  
    }

    int max_count = 0;
    for (const auto &p : counts) {
        if (p.second > max_count) {
            max_count = p.second;
        }
    }
    vector<pair<int, int>> result;
    for (const auto &p : counts) {
        if (p.second == max_count) {
            result.emplace_back(p.first, p.second);
        }
    }

    return result;
}

int main() {
    vector<int> v = {1, 1, 3, 5, 8, 9, 5, 8, 8, 5};

    auto res = most_frequent(v);
    for (const auto &p : res) {
        cout << "wartosc = " << p.first
                  << ", liczba wystapien = " << p.second << "\n";
    }
}
