#include <iostream>
#include<algorithm>
using namespace std;
struct People{
    int l , r;
    int cha;
    friend bool operator < (const People& a , const People& b){
        return a.cha > b.cha;
    }
}peo[1001];
int main(){
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> peo[i].l >> peo[i].r;
        peo[i].cha = peo[i].l - peo[i].r;
    }
    sort(peo , peo + n);
    for(int i = 0 ; i < n ; i++){
        cout << peo[i].l << " " << peo[i].r << endl;
    }
}