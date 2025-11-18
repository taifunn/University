#include <bits/stdc++.h>
using namespace std;
#define D double 

double f(double x){
	return pow(x, 5) - x + 1.0D;
}
double df(double x){
	return 5.0D * pow(x, 4) - 1.0D;
}
double bisekcja(int t){
	double l = -2.0D, r = -1.0D;
	double md;
	while(t--){
		md = (l + r)/2.0D;
		if(f(md) < 0) l = md;
		else r = md;
	}
	return md;
}
double newton(int t){
	double res = -1.0D;
	while(t--){
		res = res - f(res)/df(res);
	}
	return res;
}
double sieczne(int t){
	double x0 = -2.0D;
	double x1 = -1.0D;
	while(t--){
		double cp = x1;
		double mian = f(x1) - f(x0);
		if(mian == 0.0D) mian = 1e-16;
		x1 = x1 - f(x1)*(x1 - x0)/mian;
		x0 = cp;
	}
	return x1;
}
double falsi(int t){
	double l = -2.0D, r = -1.0D;
	double res = -2.0D;
	while(t--){
		double mian = f(r) - f(l);
		if(mian == 0.0D) mian = 1e-16;
		res = (r * f(r) - l * f(l))/mian;
		if(f(l) * f(res) < 0.0D) r = res;
		else l = res;
	}
	return res;
}
int main(){
	cout.precision(20);
	for(int i = 3; i <= 50; i++){
		cout << i <<": " << "b = " << bisekcja(i) << ", n = " << newton(i) << ", s = " << sieczne(i) << ", f = " << falsi(i) << "\n";
	}
	return 0;
}
