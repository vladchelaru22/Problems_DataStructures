#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
class Complex{
    double mReal;
    double mImag;
public:
    Complex(double real,double imag){
       mReal=real;
       mImag=imag;
    }
    Complex(){
        mReal=0;
        mImag=0;
    }
    double norm(){
        double module;
        module= sqrt((mReal*mReal)+(mImag*mImag));
        return module;
    }
    void afisare(){
        cout<<mReal<<" "<<mImag;
    }
};
int main() {
    char virgula;
    double max;
    int n;
    double real,imaginar;
    cin>>n;
    vector<Complex> numere;
    for (int i = 0; i < n; ++i) {
        cin>>real>>virgula>>imaginar;
        Complex nr(real,imaginar);
        numere.push_back(nr);
    }
    max=numere[0].norm();
    for (int i = 0; i < n; ++i) {
        if(numere[i].norm()<max)
            max=numere[i].norm();
    }
    for (int i = 0; i < n; ++i) {
        if(max==numere[i].norm()){
            numere[i].afisare();
            break;
        }
            
    }

    return 0;
}