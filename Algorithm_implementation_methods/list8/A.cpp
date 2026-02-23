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
        if(n % 2 != 0){
            res.push_back(0);
            continue;
        }
        res.push_back((n/4)+1);
    }
    for(int r : res){
        cout << r << "\n";
    }
    return 0;
}