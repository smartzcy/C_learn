#include<iostream>
#include<map>
using namespace std;
int main(){
    int n , m;
    map<int,string> map;
    cin >> n >> m;
    for(int i = 0; i < n;i++){
        int num;
        string str;
        cin >> num >> str;
        map.insert(pair<int,string>(num,str));
    }
    for(int i = 0 ; i < m;i++){
        int num;
        cin >> num;
        if(i == 0) cout << map.find(num) -> second;
        else cout << " " << map.find(num) -> second;
    }
}