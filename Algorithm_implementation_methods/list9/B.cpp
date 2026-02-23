#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int s = (1 << (n + 1));
    vector<int> a(s);
    for(int i=2; i<s; i++){
        cin >> a[i];
    }
    int res = 0;
    for(int i = (1 << n) - 1; i >= 1; i--){
        int l = 2*i;
        int r = 2*i + 1;
        int dif = abs(a[l] - a[r]);
        res += dif;
        a[i] += max(a[l], a[r]);
    }
    cout << res << "\n";
    return 0;
}