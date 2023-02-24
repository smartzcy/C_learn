#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int x = n / 100;
    int y = n / 10 - x * 10;
    int z = n % 10;;
    for(int i = 0 ; i < x;i++)
        cout << "B";
    for(int i = 0 ; i < y;i++)
        cout << "S";
    for(int i = 1; i <= z;i++)
        cout << i;
    cout << endl;
}