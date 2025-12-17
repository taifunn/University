#include <bits/stdc++.h>
using namespace std;

class line_writer {
    unique_ptr<ofstream> out;
public:
    line_writer(const string& name)
        : out(make_unique<ofstream>(name, ios::out | ios::trunc)) {}

    void write_line(const string& s){
        (*out) << s << "\n";
    }

    ~line_writer(){
        if(out && out->is_open()) out->close();
        cout << "zamknieto plik\n";
    }
};

int main(){
    auto w1 = make_shared<line_writer>("out.txt");
    shared_ptr<line_writer> w2 = w1;

    w1-> write_line("Dzien");
    {
        auto w3= w2;
        w3-> write_line("dobry");
        cout << "referencje: " << w1.use_count() << "\n";
    } 
    cout << "referencje: " << w1.use_count() << "\n";
    w2-> write_line("lalalala");
}