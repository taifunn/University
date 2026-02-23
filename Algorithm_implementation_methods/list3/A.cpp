#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int q;
    cin >> q;
    vector<long long> res;
    while(q--){
        string s, t;
        cin >> s >> t;

        if(t == "a"){
            res.push_back(1);
            continue;
        }
        
        bool ma_a = 0;
        for(char &c : t){
            if(c == 'a'){
                ma_a = 1;
                break;
            }
        }
        if(ma_a){
            res.push_back(-1);
            continue;
        }
        
        res.push_back(1LL << s.size());
    }

    for(long long r : res){
        cout << r << "\n";
    }

    return 0;
}