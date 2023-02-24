#include<iostream>
using namespace std;
int main(){
    int num[24];
    for(int i = 0 ; i < 24;i++){
        cin >> num[i];
    }
    int n , k = 0;
    while(cin >> n){
        if(n < 0 || n > 23) break;
        if(k == 0) k = 1;
        else if(k == 1) cout << endl;
        cout << num[n] << " ";
        if(num[n] > 50) cout << "Yes";
        else cout << "No";
    }
    return 0;
}