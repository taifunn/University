#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define ll long long

ll pot(int base, int exp){
    ll res = 1;
    for(int i = 0; i < exp; i++){
        res *= base;
    }
    return res;
}

ll solve(int n, int k, vector<int> &a){
    ll res = 0;
    for(int i=0; i<n-1; i++){
        ll max = pot(10, a[i+1]-a[i]) - 1;
        if(k < max){
            res += (k+1) * pot(10, a[i]);
            k = -1;
            break;
        } else {
            res += max * pot(10, a[i]);
            k -= max;
        }
    }
    if(k != -1){
        res += (k+1) * pot(10, a[n-1]);
    }
    return res;
}

int main(){
    int q;
    cin >> q;
    vector<ll> res;
    while(q--){
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        res.push_back(solve(n, k, a));
    }
    for(ll r : res){
        cout << r << "\n";
    }
    return 0;
}