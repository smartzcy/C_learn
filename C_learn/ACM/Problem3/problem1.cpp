#include<iostream>
using namespace std;
int main(){
    long long num;
    int n;
    cin >> n;
    for(int i = 0 ; i < n;i++){
        cin >> num;
        cout << num  / 2 + num % 2 << endl;
    }
    return 0;
}