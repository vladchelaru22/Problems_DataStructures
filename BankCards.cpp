#include <iostream>
#include <vector>
#include <algorithm>
#include<set>
#include<iomanip>
using namespace std;

bool cmp(pair<string,float>&a,pair<string,float>&b){
    return a.second<b.second;
}
bool cmp2(pair<string,float>&a,pair<string,float>&b){
    if(a.second==b.second)
        return a.first<b.first;
    return a.second>b.second;
}
int main() {
    string prenume,tip_card,cod_card,data_expirare,command;
    float sold;
    cin>>command;
    if(command=="stats")
    {
        vector<string>carduri;
        map<string,int>frecvente;
        while(cin>>prenume>>tip_card>>cod_card>>data_expirare>>sold){
            carduri.push_back(tip_card);
        }
        for(string card:carduri)
            frecvente[card]++;
        for (auto it = frecvente.begin(); it != frecvente.end(); it++)
            std::cout << it->first << "," << it->second << std::endl;
        }
    }
    if(command=="debt"){
        vector<pair<string,float>>datornici;
        float datorie_totala=0;
        while(cin>>prenume>>tip_card>>cod_card>>data_expirare>>sold){
            if(sold<0){
                datornici.push_back({prenume,sold});
                datorie_totala=datorie_totala+sold;
            }
        }
        cout<<fixed<<setprecision(2)<<datorie_totala<<endl;
        sort(datornici.begin(),datornici.end(),cmp);
        for (int i = 0; i < datornici.size(); ++i) {
            cout<<datornici[i].first<<" ";
        }
        cout<<endl;
    }
    if(command=="search"){
        string cautat_cod,cautat_nume,cautat_banca,cautat_data;
        int gasit=0;
        float cautat_sold;
        cin>>cautat_cod;
        while(cin>>prenume>>tip_card>>cod_card>>data_expirare>>sold){
            if(cod_card==cautat_cod){
                gasit=1;
                cautat_nume=prenume;
                cautat_banca=tip_card;
                cautat_data=data_expirare;
                cautat_sold=sold;
            }
        }
        if(gasit==0)
            cout<<"CARD INVALID"<<endl;
        else {cout<<cautat_nume<<" "<<cautat_banca<<" "<<cautat_cod<<" "<<cautat_data<<" ";
            cout<<fixed<<setprecision(2)<<cautat_sold<<endl;}
    }
   if(command=="expiration"){
        set<string>date_distincte;
        int an_cautat,counter=0,zi,luna,an;
        char slash;
        cin>>an_cautat;
        while(cin>>prenume>>tip_card>>cod_card>>data_expirare>>sold){
            istringstream is(data_expirare);
            is>>zi>>slash>>luna>>slash>>an;
            if(an==an_cautat)
                date_distincte.insert(data_expirare);
        }
        cout<<date_distincte.size()<<endl;
    }
    if(command=="richest"){
        vector<pair<string,float>>bogati;
        int nr_bogati;
        cin>>nr_bogati;
        while(cin>>prenume>>tip_card>>cod_card>>data_expirare>>sold){
            bogati.push_back({prenume,sold});
        }
        sort(bogati.begin(),bogati.end(),cmp2);
        for (int i = 0; i < nr_bogati; ++i) {
            cout<<bogati[i].first<<endl;
        }
    }

    return 0;
}
