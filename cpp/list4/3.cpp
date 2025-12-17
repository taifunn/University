#include <utility>
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <string>
using namespace std;

template<typename T>
struct Range{
    T a, b;
    bool operator()(const T& x) const {
        return a < x && x < b;
    }
};

struct pick_k{
    int s;
    int k;
    int i=0;

    template<typename T>
    bool operator()(const T&){
        bool res = (i>=s) && ((i-s)%k == 0);
        i++;
        return res;
    }
};

template<typename T>
struct minimax{
    void operator()(pair<T,T>& acc, const T& x) const {
        if(x<acc.first) acc.first = x;
        if(acc.second < x) acc.second = x;
    }
};

template<typename acc, typename T>
struct Add{
    void operator()(acc& a, const T& x) const {
        a += x;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cout.setf(ios::fixed);

    vector<double> V = {3.5, 2.1, 4.7, 1.0, 5.9, 8.2, 7.4, 6.3};
    list<int>      L = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    set<string>    S = {"ala", "ma", "kota", "i", "psa"};

    Range<double> rD{2.0, 7.0};
    Range<int>    rI{2, 6};
    Range<string> rS{string("b"), string("o")};

    cout << "vector<double> w (2,7): ";
    for (const auto& x : V) if (rD(x)) cout << x << ' ';
    cout << '\n';

    cout << "list<int> w (2,6):      ";
    for (const auto& x : L) if (rI(x)) cout << x << ' ';
    cout << '\n';

    cout << "set<string> w (\"b\",\"o\"): ";
    for (const auto& x : S) if (rS(x)) cout << x << ' ';
    cout << "\n\n";

    pick_k pkD{1, 2};
    pick_k pkI{2, 3}; 
    pick_k pkS{0, 2}; 

    cout << "vector<double> co 2. od 1.: ";
    for (const auto& x : V) if (pkD(x)) cout << x << ' ';
    cout << '\n';

    cout << "list<int> co 3. od 2.:      ";
    for (const auto& x : L) if (pkI(x)) cout << x << ' ';
    cout << '\n';

    cout << "set<string> co 2. od 0.:    ";
    for (const auto& x : S) if (pkS(x)) cout << x << ' ';
    cout << "\n\n";

    pair<double,double> mmV{V.front(), V.front()};
    pair<int,int>       mmL{L.front(), L.front()};
    pair<string,string> mmS{*S.begin(), *S.begin()};

    minimax<double> mmd; for (const auto& x : V) mmd(mmV, x);
    minimax<int>    mmi; for (const auto& x : L) mmi(mmL, x);
    minimax<string> mms; for (const auto& x : S) mms(mmS, x);

    cout << "min/max vector<double>: " << mmV.first  << " / " << mmV.second << '\n';
    cout << "min/max list<int>:      " << mmL.first  << " / " << mmL.second << '\n';
    cout << "min/max set<string>:    " << mmS.first  << " / " << mmS.second << "\n\n";

    Add<double,double> addDD;
    Add<long long,int> addII;
    Add<string,string> addSS;

    double     sumV = 0.0;  for (const auto& x : V) addDD(sumV, x);
    long long  sumL = 0;    for (const auto& x : L) addII(sumL, x);
    string     catS;        for (const auto& x : S) addSS(catS, x);

    cout << "Suma vector<double>:      " << sumV << '\n';
    cout << "Suma list<int>:           " << sumL << '\n';
    cout << "Konkatenacja set<string>: " << catS << '\n';
}