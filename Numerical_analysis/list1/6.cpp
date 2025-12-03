#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

#define d float

d pi(int k)
{
    int zn;
    if(k%2==0) zn = 1;
    else zn = -1;
    return zn/(2.0*k+1);
}

int main()
{
    cout<<setprecision(20)<<fixed;
    d suma=0;
    for(int i=0;i<2000000;i++)
    {
        d wyr=pi(i);
        suma+=wyr;
        cout<<suma*4<<" "<<abs(M_PI-suma*4)<<"\n";
        if(abs(M_PI-suma*4)<1/1000000.0)
        {
            cout<<"k="<<i<<"\n";
            break;
        }
    }
    return 0;
}