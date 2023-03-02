#include<iostream>
#include<map>
using namespace std;
int main(){
    int n;
    string cuvant,definitie;
    map<string,string>cuvinte;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++){
        getline(cin,cuvant,',');
        getline(cin,definitie);
        if(cuvinte.find(cuvant)!=cuvinte.end())
            cuvinte.erase(cuvant);
        cuvinte.insert(pair<string,string>(cuvant,definitie));
    }
    for (auto & itr : cuvinte) {
        cout << itr.first <<": " << itr.second<<endl;}
    return 0;
}