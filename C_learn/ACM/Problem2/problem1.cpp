#include<iostream>
using namespace std;
int main(){
    int n , num;
    cin >> n;
    for(int i = 0 ; i < n;i++){
        cin >> num;
        if(num == 2) cout << 2 << endl;
        else if(num % 2 == 1) cout << 3 << endl;
    }
    return 0;
}