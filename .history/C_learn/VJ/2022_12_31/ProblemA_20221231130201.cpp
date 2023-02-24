#include<iostream>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int n , m;
        cin >> n >> m;
        if(n == 2) cout << m << endl;
        else cout << 2 * m << endl;
    }
    return 0;
}