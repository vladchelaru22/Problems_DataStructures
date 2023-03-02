#include <iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include <set>
using namespace std;

bool castigat(vector<int>a,vector<int>b){
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int size_a=a.size();
    for(int i=0;i<size_a;i++){
        if(a[i]!=b[i])
            return false;
    }
    return true;
}

int ghicite(vector<int>a,vector<int>b){
    set<int>comune;
    int size_a=a.size();
    int size_b=b.size();
    for (int i = 0; i < size_a; ++i) {
        for (int j = 0; j < size_b; ++j) {
            if(a[i]==b[j])
                comune.insert(a[i]);
        }
    }
    return comune.size();
}


bool cmp(pair<int,int>&a,pair<int,int>&b){
    if(a.second==b.second)
        return a.first<b.first;
    return a.second<b.second;
}


int main() {
    char subpunct;
    vector<int>combinatia;
    vector<int>toate_num;
    int num;
    string nume,prenume,line;
    for (int i = 0; i < 6; ++i) {
        cin>>num;
        combinatia.push_back(num);
    }
    cin>>subpunct;
    if(subpunct=='A'){
        map<int,int>aparitii_numar;
        while(cin>>nume>>prenume){
            getline(cin,line);
            istringstream is( line );
            int n;
            while(is>>n){
                toate_num.push_back(n);
            }
        }
        sort(toate_num.begin(),toate_num.end());
        int numarul_max=toate_num[0],aparitii_max=0;
        int num_size=toate_num.size();
        for (int i = 0; i <num_size; ++i) {
            if(numarul_max==toate_num[i])
                aparitii_max++;
            if(numarul_max!=toate_num[i])
            {
                aparitii_numar.insert({numarul_max,aparitii_max});
                aparitii_max=1;
                numarul_max=toate_num[i];
            }
        }
        numarul_max=0;
        aparitii_max=0;
        for (auto it:aparitii_numar) {
            if(it.second>aparitii_max) {
                numarul_max = it.first;
                aparitii_max=it.second;
            }
            if(it.second==aparitii_max){
                if(numarul_max>it.first)
                    numarul_max=it.first;
            }
        }
        cout<<numarul_max<<" "<<aparitii_max<<endl;
    }

    if(subpunct=='B'){
        vector<int>bilete_pe_linie;
        while(cin>>nume>>prenume){
            getline(cin,line);
            istringstream is( line );
            int n,counter=0,numar_bilete;
            while(is>>n){
                counter++;
            }
            numar_bilete=counter/6;
            bilete_pe_linie.push_back(numar_bilete);
        }
        sort(bilete_pe_linie.begin(),bilete_pe_linie.end(),greater<int>());
        cout<<*bilete_pe_linie.begin()<<endl;
    }

    if(subpunct=='C'){
        map<int,int>aparitii_numar;
        vector<pair<int,int>>aparitii_sortate;
        while(cin>>nume>>prenume){
            getline(cin,line);
            istringstream is( line );
            int n;
            while(is>>n){
                toate_num.push_back(n);
            }
        }
        sort(toate_num.begin(),toate_num.end());
        int numarul_max=toate_num[0],aparitii_max=0;
        int num_size=toate_num.size();
        for (int i = 0; i < num_size ; ++i) {
            if(numarul_max==toate_num[i])
                aparitii_max++;
            if(numarul_max!=toate_num[i] || i==num_size-1)
            {
                aparitii_numar.insert({numarul_max,aparitii_max});
                aparitii_max=1;
                numarul_max=toate_num[i];
            }
        }
        for (int i = 1; i <= 49; ++i) {
            if(aparitii_numar.count(i)==0)
                aparitii_numar.insert({i,0});
            else continue;
        }
        numarul_max=0;
        aparitii_max=0;
        for(auto it:aparitii_numar){
            aparitii_sortate.push_back(it);
        }
        sort(aparitii_sortate.begin(),aparitii_sortate.end(),cmp);
        int aparitii_size=aparitii_sortate.size();
        for (int i = 0; i < aparitii_size; ++i) {
            cout<<aparitii_sortate[i].first<<" ";
        }
    }

    if(subpunct=='D'){
        queue<int>numere;
        vector<int>o_combinatie;
        while(cin>>nume>>prenume){
            getline(cin,line);
            istringstream is( line );
            int n;
            while(is>>n){
                numere.push(n);
            }
        }
        int numar_combinatii=numere.size()/6;
        int max_gasite=0;
        for (int i = 0; i < numar_combinatii; ++i) {
            for (int j = 0; j < 6; ++j) {
                o_combinatie.push_back(numere.front());
                numere.pop();
            }
            int gasite= ghicite(o_combinatie,combinatia);
            if(gasite>max_gasite)
                max_gasite=gasite;
            o_combinatie.clear();
        }
        cout<<max_gasite;
    }

    if(subpunct=='E'){
        map<string,string>castigatori;
        vector<int>o_combinatie;
        queue<int>combinatii_jucator;
        while(cin>>nume>>prenume){
            getline(cin,line);
            istringstream is( line );
            int n;
            while(is>>n){
                combinatii_jucator.push(n);

            }
            int nr_combinatii=combinatii_jucator.size()/6;
            for (int i = 0; i < nr_combinatii; ++i) {
                for (int j = 0; j < 6; ++j) {
                    o_combinatie.push_back(combinatii_jucator.front());
                    combinatii_jucator.pop();
                }
                if(castigat(o_combinatie, combinatia))
                    castigatori.insert({nume,prenume});
            }
        }
        if(castigatori.size()==0)
        {
            cout<<"Niciun castigator";
        }
        else{
            for (const auto& it:castigatori) {
                cout<<it.first<<" "<<it.second<<endl;
            }
        }
    }
    return 0;
}