#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main(){
    int n;
    ll d;
    cin >> n >> d;

    vector<ll> p(n);
    for(int i=0; i<n; i++){
        cin >> p[i];
    }
    sort(p.begin(), p.end());

    int wins = 0;
    int l = 0;
    int r = n-1;
    while(l <= r){
        ll curr = p[r];
        ll need = (d/curr) + 1;

        if(r - l +1 >= need){
            wins++;
            r--;
            l += (need -1);
        } else {
            break;
        }
    }
    cout << wins << "\n";
    return 0;
}