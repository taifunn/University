#include <bits/stdc++.h>
using namespace std;

int moves(string s, int n){
    int change = 0;
    for(int i=0; i+1<n; i++){
        if(s[i] != s[i+1]) change++;
    }
    if(s[0] == '1') change++;
    return change;
}

int main(){
    int q;
    vector<int> res;
    cin >> q;
    while(q--){
        int n;
        string s;

        cin >> n;
        cin >> s;
        res.push_back(moves(s, n));
    }
    for(int r: res){
        cout << r << "\n";
    }
}

using namespace std;

int moves(string s, int n){
    int change = 0;
    for(int i=0; i+1<n; i++){
        if(s[i] != s[i+1]) change++;
    }
    if(s[0] == '1') change++;
    return change;
}

int main(){
    int q;
    vector<int> res;
    cin >> q;
    while(q--){
        int n;
        string s;

        cin >> n;
        cin >> s;
        res.push_back(moves(s, n));
    }
    for(int r: res){
        cout << r << "\n";
    }
}
