#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    //7x + 21k
    int k = 1;
    while(true){
        for(int x = 100 ; x >= 1 ;x--){
            if((7 * x + 21 * k) * 52 == n){
                cout << x << endl;
                cout << k;
                return 0;
            }
        }
        k++;
    }
    return 0;
}