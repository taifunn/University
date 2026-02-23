#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int q;
    cin >> q;
    vector<int> res;
    while(q--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int r = n;
        for(int i=0; i<2*n-1; i++){
            if(s[i] == ')' && s[i+1] == '('){
                r -= 1;
            }
        }
        res.push_back(r);
    }
    for(int r : res){
        cout << r << "\n";
    }
    return 0;
}