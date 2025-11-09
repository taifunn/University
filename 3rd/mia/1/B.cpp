#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    vector<int> res;
    while(q--){
        int n;
        cin >> n;
        vector<int> a;
        map<int, vector<int> > m;
        vector<int> id(n, -1);
        for(int i=0; i<n; i++){
            int b;
            cin >> b;
            a.push_back(b);
            m[b].push_back(i);
        }
        for(auto w: m){
            vector<int> cur = w.second;
            for(int i=w.first-1; i<cur.size(); i++){
                id[cur[i]] = cur[i - (w.first-1)];
            }
        }
        vector<int> dp(n, 0);
        if(a[0] == 1) dp[0] = 1;
        for(int i=1; i<n; i++){
            dp[i] = dp[i-1];
            if(id[i] != -1){
                if(id[i] == 0) dp[i] = max(dp[i], a[i]);
                else dp[i] = max(dp[i], (a[i] + dp[id[i]-1]));
            }
        }
        int maks=0;
        for(auto d: dp){
            if(d>maks) maks = d;
        }
        res.push_back(maks);
    }
    for(auto r: res){
        cout << r <<'\n';
    }
}