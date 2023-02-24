#include<iostream>
#include<map>
using namespace std;
int main(){
    int n , q;
    cin >> n >> q;
    map<pair<int,int>,int> map1;
    while(q--){
        int m;
        cin >> m;
        if(m == 1){
            int i , j , k;
            cin >> i >> j >> k;
            map1[{i,j}] = k;
        }else if(m == 2){
            int i , j;
            cin >> i >> j;
            cout << map1[{i,j}] << endl;
        }
    }
    return 0;
}