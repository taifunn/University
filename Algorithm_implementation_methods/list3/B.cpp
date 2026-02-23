#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define ll long long

int prep[210];

bool is_good(int n){
    if(n % 2 == 0) return false;
    if(n % 3 == 0) return false;
    if(n % 5 == 0) return false;
    if(n % 7 == 0) return false;
    return true;
}

void preprocess(){
    int cnt = 0;
    for(int i = 0; i < 210; i++){
        if(is_good(i)){
            cnt++;
        }
        prep[i] = cnt;
    }
}

ll count(long long n){
    if(n<0) return 0;
    ll full = n / 210;
    int rem = n % 210;
    
    return full * prep[209] + prep[rem];
}

int main(){
    vector<ll> res;
    int q;
    cin >> q;
    ll l, r;
    preprocess();
    while (q--){
        cin >> l >> r;
        ll ans = count(r) - count(l - 1);
        res.push_back(ans);
    }
    for(ll r : res){
        cout << r << "\n";
    }
    return 0;
}