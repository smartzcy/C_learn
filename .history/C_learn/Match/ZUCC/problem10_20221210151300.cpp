#include<iostream>
using namespace std;
int main(){
    int n;
    int a = 0 , b = 0;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        int num;
        cin >> num;
        if(num % 2 == 0) b++;
        else a++;
    }
    if(a % 2 == 0) cout << "Bob";
    else cout << "Alice";
}