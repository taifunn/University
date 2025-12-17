#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]){
    if(argc != 3){
        cerr << "Usage: " << argv[0] << " <dlugosc_tekstu> <nazwa_pliku.txt>\n";
        return 1;
    }
    long long target_len = 0;
    try{
        target_len = stoll(argv[1]);
    }
    catch(...){
        cerr << "blad: dlugosc tekstu musi byc liczba calkowita\n";
        return 1;
    }
    if (target_len <= 0) {
        std::cerr << "Blad: dlugosc_tekstu musi byc dodatnia.\n";
        return 1;
    }
    string filename = argv[2];
    ofstream file(filename);
    if(!file){
        cerr << "blad otwierania    " << filename << "!\n";
        return 1;
    }

    random_device rd;
    mt19937 gen(rd());

    vector<double> weights = {
        9.16, 
        1.93, 
        4.49, 
        3.35, 
        9.81, 
        0.26,
        1.46,
        1.25,
        8.83,
        2.28, 
        3.01, 
        4.62,
        2.81,
        5.85,
        8.32, 
        2.87,
        0.00, 
        4.15,
        4.85,
        3.85, 
        2.06, 
        0.00,
        4.11,
        0.00, 
        4.03,
        6.34 
    };

    discrete_distribution<int> dist(weights.begin(), weights.end());
    binomial_distribution<int> word_len_dist(11, 0.5);

    string text;
    text.reserve(target_len);

    while(static_cast<long long>(text.size()) < target_len){
        int word_len = word_len_dist(gen) + 1;
        if(!text.empty()){
            if (static_cast<long long>(text.size()) + 1 > target_len) {
                break;
            }
            text.push_back(' ');
        }
        for (int i = 0; i < word_len; ++i) {
            if (static_cast<long long>(text.size()) >= target_len) {
                break;
            }
            int idx = dist(gen);
            char c = static_cast<char>('a' + idx);
            text.push_back(c);
        }
    }
    file << text;
    file.close();
    return 0;
}