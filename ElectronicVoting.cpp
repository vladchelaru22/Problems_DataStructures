#include <iostream>
#include <fstream>
#include <set>
#include <iomanip>
#include <vector>
using namespace std;
bool verify_age(string cnp){
    if(cnp[0]=='1' || cnp[0]=='2' || cnp[0]=='3' || cnp[0]=='4')
        return true;
    if(cnp[0]=='5' || cnp[0]=='6'){
        if(cnp[1]!='0')
            return false;
        if(cnp[2]!='0')
            return false;
        if(cnp[3]!='0')
            return false;
        if(cnp[4]-'0'>4)
            return false;
    }
    return true;
}


int main() {


    set<string>evidenta;
    set<string>votanti;
    vector<string>candidati;
    int frauda=0;
    double nr_voturi=0;
    char delimiter=',',comanda;
    string nume,strada,CNP,serie,candidat;
    ifstream  file;
    file.open("evidenta.csv");
    while(getline(file,nume,delimiter) && getline(file,strada,delimiter) && getline(file,CNP,delimiter) && getline(file,serie))
    {
        evidenta.insert(CNP);
    }
    file.close();
    while(cin>>comanda){
        if(comanda=='+')
        {
            cin>>CNP;
            getline(cin,candidat);
            if(evidenta.count(CNP)==0) {
                cout << "CNP invalid" << endl;
                frauda++;
                continue;
            }
            if(votanti.count(CNP)>0){
                cout<<"Vot deja inregistrat"<<endl;
                frauda++;
                continue;
            }

            if(verify_age(CNP)==false){
                cout<<"Persoana minora"<<endl;
                continue;
            }
            if(evidenta.count(CNP)==1 && votanti.count(CNP)==0 && verify_age(CNP)){
                nr_voturi++;
                candidati.push_back(candidat);
                votanti.insert(CNP);
            }
        }
        if(comanda=='?'){

            cout<<"Statistici"<<endl;
            cout<<"=========="<<endl;
            for (int i = 0; i < candidati.size(); ++i) {
                cout<<candidati[i]<<": 1 voturi (";
                double procentaj=100/nr_voturi;
                cout<<fixed<<setprecision(2)<<procentaj<<"%)"<<endl;
            }
            cout<<"Incercari de frauda: "<<frauda<<endl;
        }
        if(comanda=='*'){

            cout<<"Statistici"<<endl;
            cout<<"=========="<<endl;
                for (int i = 0; i < candidati.size(); ++i) {
                    cout << candidati[i] << ": 1 voturi (";
                    double procentaj=100/nr_voturi;
                    cout << fixed << setprecision(2) << procentaj << "%)" << endl;
                }
                cout << "Incercari de frauda: " << frauda;
                return 0;
            }
        }
    }
