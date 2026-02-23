#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(int n,vector<int> &a){
    if(a[n-1] == -1 && a[0] == -1){
        a[0] = 0;
        a[n-1] = 0;
    }
    else if(a[n-1] == -1 && a[0] != -1){
        a[n-1] = a[0];
    }
    else if(a[n-1] != -1 && a[0] == -1){
        a[0] = a[n-1];
    }
    for(int i=0; i<n; i++){
        if(a[i] == -1){
            a[i] = 0;
        }   
    }
}

int main(){
    int q;
    cin >> q;
    vector<vector<int>> res;
    vector<int> difs;

    for(int i=0; i<q; i++){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        solve(n, a);
        difs.push_back(abs(a[n-1] - a[0]));
        res.push_back(a);
        cout << "\n";
    }
    for(int i=0; i<q; i++){
        cout << difs[i] << "\n";
        for(int val : res[i]){
            cout << val << " ";
        }
        cout << "\n";
    }
    return 0;
}