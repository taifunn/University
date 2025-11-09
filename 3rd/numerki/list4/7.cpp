#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double prw(double x){
	double y = x;
	for(int i = 0; i < 20; i++){
		y = 0.5 * (y + x/y);
	}
	return y;
}
void f(double m){
	double copy = m;
	int c = 0;
	while(m >= 1.0){
		++c;
		m /= 2.0;
	}
	while(m < 0.5){
		--c;
		m *= 2.0;
	}
	if(c % 2){
		m *= 2.0;
		--c;
	}
	c /= 2;
	double pw = pow(2.0, c);
	cout << "f(" << copy << ") = " << prw(m) * pw << "\n";
}
int main(){
	vector<double> A = {9, 0.5, 1.0, 2.0, 10.0, 1e-6, 1e6, 123.456};
    for(auto a : A) {
		f(a);
	}
	
}
