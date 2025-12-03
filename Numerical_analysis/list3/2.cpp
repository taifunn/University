#include <bits/stdc++.h>
#define ld long double
using namespace std;

void brut(ld a, ld b, ld c){
	ld delta = b * b - a * c * 4.0L;
	if(delta < 0.0L){
		cout << "Bez miejsc\n";
	}
	else if(delta == 0.0L){
		cout << "jedno\n";
		cout <<  -b/(a * 2.0L) << "\n";
	}
	else{
		ld x1 = (-b - sqrtl(delta)) / (a * 2.0L);
		ld x2 = (-b + sqrtl(delta)) / (a * 2.0L);
		cout << "dwa\n";
		cout << x1 << "\n" << x2 << "\n";
	}
}
void better(ld a, ld b, ld c){
	ld delta = b * b - a * c * 4.0L;
	if(delta < 0.0L){
		cout << "Bez miejsc\n";
	}
	else if(delta == 0.0L){
		cout << "jedno\n";
		cout <<  -b/(a * 2.0L) << "\n";
	}
	else{
		ld x1 = (b > 0.0L) ? (-b - sqrtl(delta)) / (a * 2.0L) : (-b + sqrtl(delta)) / (a * 2.0L);
		ld x2 = c / (x1 * a);
		cout << "dwa\n";
		cout << x1 << "\n" << x2 << "\n";
	}
}
int main(){
    cout.setf(std::ios::fixed);
    cout << setprecision(40);

    // b bardzo duże dodatnie
    cout << "\n=== x^2 + 1e16 x + 1 ===\n";
    cout << "[brut]\n";   brut(1.0L, 1e16L, 1.0L);
    cout << "[better]\n"; better(1.0L, 1e16L, 1.0L);

    // b bardzo duże ujemne
    cout << "\n=== x^2 - 1e16 x + 1 ===\n";
    cout << "[brut]\n";   brut(1.0L, -1e16L, 1.0L);
    cout << "[better]\n"; better(1.0L, -1e16L, 1.0L);

    //bardzo małe c
    cout << "\n=== x^2 + 1e12 x + 1e-20 ===\n";
    cout << "[brut]\n";   brut(1.0L, 1e12L, 1e-20L);
    cout << "[better]\n"; better(1.0L, 1e12L, 1e-20L);

    //małe a, duże b
    cout << "\n=== 1e-20 x^2 + 1e8 x + 1 ===\n";
    cout << "[brut]\n";   brut(1e-20L, 1e8L, 1.0L);
    cout << "[better]\n"; better(1e-20L, 1e8L, 1.0L);

    // drugi znak b i małe a
    cout << "\n=== 1e-20 x^2 - 1e8 x + 1 ===\n";
    cout << "[brut]\n";   brut(1e-20L, -1e8L, 1.0L);
    cout << "[better]\n"; better(1e-20L, -1e8L, 1.0L);

    return 0;
}