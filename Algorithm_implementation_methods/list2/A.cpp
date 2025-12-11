#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int q;
    cin >> q;
    vector<ll> res_all;
    while(q--){
        int n;
        cin >> n;
        vector<ll> mins;
        vector<ll> sec;

        for(int i=0; i<n; i++){
            int m;
            cin >> m;

            vector<ll> tab(m);
            for(int j=0; j<m; j++){
                cin >> tab[j];
            }

            sort(tab.begin(), tab.end());
            mins.push_back(tab[0]);
            sec.push_back(tab[1]);

        }
        ll sum = 0;
        for(auto s: sec){
            sum += s;
        }
        ll res = sum - *min_element(sec.begin(), sec.end()) + *min_element(mins.begin(), mins.end());

        res_all.push_back(res);
    }
    for(auto r: res_all){
        cout << r << "\n";
    }
    return 0;
}