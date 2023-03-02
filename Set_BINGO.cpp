#include <iostream>
#include<set>
using namespace std;

int main() {
    set<int> mySet;
    int n,nr;
    cin>>n;
    for (int i = 0; i < n*n; ++i) {
        cin>>nr;
        mySet.insert(nr);
    }
    while(cin>>nr){
        mySet.erase(nr);    
    }
    if(mySet.empty()== true)
        cout<<"BINGO!";
    else{
        for(std::set<int>::iterator it = mySet.begin(); it != mySet.end(); it++) {
            printf("%d ", *it);
        }
    }
    return 0;
}
