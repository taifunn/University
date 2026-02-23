#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

vector<ll> res;

ll sum(ll n){
    return n * (n + 1) / 2;
}

ll emote_cnt(ll k, ll cnt){
    if(cnt <= k){
        return sum(cnt);
    } else {
        ll total = k*k;
        ll rem = (2*k -1) - cnt;
        return total - sum(rem);
    }
}

void solve(){
    ll k, x;
    cin >> k >> x;
    if(k*k<x){
        res.push_back(2*k -1);
        return;
    }

    ll l = 1;
    ll r = 2*k -1;
    ll ans = 2*k-1;

    while(l <= r){
        ll mid = (l + r) / 2;
        ll cnt = emote_cnt(k, mid);
        if(cnt >= x){
            ans = mid;
            r = mid -1;
        } else {
            l = mid +1;
        }
    }
    res.push_back(ans);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    for(ll r : res){
        cout << r << "\n";
    }
    return 0;
}