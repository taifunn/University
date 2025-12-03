#include <bits/stdc++.h>
using namespace std;

class Zadanie
{
    uint64_t licznik=1;
public:
    Zadanie() = default;
    virtual ~Zadanie() {
        cerr << "Stan licznika: " << licznik << "\n";
    }
    void add(uint64_t x){
        licznik += x;
    }
    uint64_t val() const {
        return licznik;
    }
};

unique_ptr<Zadanie[]> fun(unique_ptr<Zadanie[]> tab, int n, uint64_t i, uint64_t m, mt19937& gen) {
    if (i > m || n <=0) return tab;

    int k = ceil(0.1*n);
    vector<int> idx(n);
    for (int j = 0; j < n; j++){
        idx[j] = j;
    }
    shuffle(idx.begin(), idx.end(), gen);    

    for (int t = 0; t < k; t++) {
        tab[idx[t]].add(i);
    }

    return fun(std::move(tab), n, i + 1, m, gen);
}

int main() {
    int n = 40;
    uint64_t m = 20;

    mt19937 rng(12345);  
    auto tab = make_unique<Zadanie[]>(n);   
    tab = fun(std::move(tab), n, 1, m, rng);

    for (int i = 0; i < n; i++) {
        cout << i << ": " << tab[i].val() << '\n';
    }
}