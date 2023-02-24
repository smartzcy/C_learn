#include<iostream>
using namespace std;
int main(){
    int T;
    cin >> T;
    for(int i = 1 ; i <= T ; i++){
        long long a , b , c;
        cin >> a >> b >> c;
        cout << "Case #" << i << ": ";
        if(a + b > c) cout << "true" << endl;
        else cout << "false" << endl;
    }
}