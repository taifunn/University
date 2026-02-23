#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int q;
    cin >> q;
    vector<string> res;
    while(q--){
        string text;
        cin >> text;
        int cnt =0;
        for(char &c : text){
            if(c == 'N'){
                cnt++;
            }
        }
        if(cnt == 1){
            res.push_back("NO");
        } else {
            res.push_back("YES");
        }
    }
    for(const string &s : res){
        cout << s << "\n";
    }
}