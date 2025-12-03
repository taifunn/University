#include <bits/stdc++.h>
#define M_PI 3.14159265358979323846L
typedef long double ld;
using namespace std;
ld arcctg(ld x){
	return atan2l(1.0L, x);
}
ld a_brut(ld x){
	return powl(x, 3) + sqrtl(powl(x, 6) + 2025.0L);
}
ld a_better(ld x){
	ld ax = fabsl(x);
	ld s = ax*ax*ax;
	ld t = sqrtl(s*s + 2025.0L);
	if (x >= 0.0L) return s + t;
	else return 2025.0L / (t + s);
}
ld b_brut(ld x){
	return powl(x, -3) * (M_PI / 2.0L - x - arcctg(x));
}

ld b_better(ld x){
    ld ax = fabsl(x);
    if (ax == 0.0L) return -1.0L/3.0L; // granica
    if (ax <= 0.01L){ //bardzo male z taylora
		ld x2 = x*x, x4 = x2*x2, x6 = x4*x2;
        return -1.0L/3.0L + x2/5.0L - x4/7.0L + x6/9.0L;
    }
    return ((M_PI / 2.0 - x) - arcctg(x) ) / (x*x*x);
}

int main(){
	//kilka testów skrajnych wartości
	cout << setprecision(10);
	for(ld x : {0.00000000000001L, 50.0l, 7183.2137L, 1e15L, -1e3L, -1e6L, -1e9L}){
		cout << "x = " << x  << ", brut = " << a_brut(x) << " better =  " << a_better(x) << "\n";
	}
	cout << "\n";
	for(ld x : {0.00000000000001L, 50.0l, 7183.2137L, 1e15L, -1e3L, -1e6L, -1e9L}){
		cout << "x = " << x  << ", brut = " << b_brut(x) << " better =  " << b_better(x) << "\n";
	}
	
}
