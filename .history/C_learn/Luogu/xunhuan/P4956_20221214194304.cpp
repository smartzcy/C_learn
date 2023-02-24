#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    //7x + 21k
    int k = 1;
    while(true){
        if((n - 21 * 52 * k) % (7 * 52) == 0) break;
        k++;
    }
    cout << (n - 21 * 52 * k) / (7 * 52) << endl;
    cout << k << endl;
}