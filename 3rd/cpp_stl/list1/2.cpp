#include <iostream>
#include <set>
#include <string>
using namespace std;

using set_string = set<string>;

int main(){
    set_string animals = {"pies", "kot", "alpaka", "chomik", "papuga"};

    for(const auto& a: animals){
        cout << a << '\n';
    }
    return 0;
}