#include <iostream>
#include <fstream>
#include <random>
using namespace std;

int main(){
    const int N = 1000;

    random_device rd;
    mt19937 gen(rd());

    uniform_real_distribution<double> uniform(0.0, 1.0);
    binomial_distribution<int> binom(10, 0.5);
    normal_distribution<double> normal(5.0, 2.0);

    {
        ofstream file("uniform.csv");
        if(!file){
            cerr << "Error opening!" << endl;
            return 1;
        }
        for(int i =0; i<N; i++){
            file << uniform(gen) << "\n";
        }
    }

    {
        ofstream file("binomial.csv");
        if(!file){
            cerr << "Error opening!" << endl;
            return 1;
        }
        for(int i =0; i<N; i++){
            file << binom(gen) << "\n";
        }
    }

    {
        ofstream file("normal.csv");
        if(!file){
            cerr << "Error opening!" << endl;
            return 1;
        }
        for(int i =0; i<N; i++){
            file << normal(gen) << "\n";
        }
    }

}
