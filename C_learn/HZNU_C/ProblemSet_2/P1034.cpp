#include<algorithm>
#include<string.h>
#include<string>
#include<iostream>
using namespace std;
struct People{
    string name;
    int b;
    int c;
}people[11000];
bool cmp(const People a,const People b){
    if(a.c == b.c){
        if(b.b == a.b){
            return a.name < b.name;
        }
        return a.b > b.b;
    }
    return a.c > b.c;
}
int main(){
    int T;
    cin>>T;
    while (T--){
        int N;
        cin>>N;
        for(int i=0; i<N; i++) cin>>people[i].name>>people[i].b>>people[i].c;
        sort(people,people + N,cmp);
        for(int i = 0; i < N; i++) cout<<people[i].name<<' '<<people[i].b<<' '<<people[i].c<<'\n';
        cout<<'\n';
    }
    return 0;
}