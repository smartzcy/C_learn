#include<iostream>
using namespace std;
int main(){
    int n , m;
    int k = 0;
    while (cin >> n >> m){
        if(k == 0){
            k = 1;
            cout << n * m;
        }else cout << " " << n * m;
        if(m != 0 && --m != 0) cout << " " << m;
    }
    cout << endl;
}