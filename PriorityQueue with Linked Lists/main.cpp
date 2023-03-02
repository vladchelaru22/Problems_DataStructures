#include "PriorityQueue.h"
#include "Patient.h"
using namespace std;
int main() {

    char semn,sex;
    string nume,prenume;
    uint32_t varsta;
    uint32_t prioritate;
    Patient pacient;
    PriorityQueue<Patient> queue(10);
    while(cin>>semn){
        if(semn=='+') {
            cin >> nume >> prenume >> varsta >> sex >> prioritate;
            pacient.firstName = nume;
            pacient.lastName = prenume;
            pacient.age = varsta;
            pacient.gender = sex;
            queue.push(pacient,prioritate);
        }
        if(semn=='-'){
            Patient englez=queue.pop();
            cout<<englez.firstName<<" "<<englez.lastName<<" "<<static_cast<uint32_t>(englez.age)<<" "<<englez.gender<<endl;
        }

        if(semn=='*')
        {
            return 0;
        }
    }



    return 0;
}