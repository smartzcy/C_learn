#include<iostream>
using namespace std;
int main(){
    string str[100];
    int k = 0;
    while(cin >> str[k++]);
    for(int i = k - 2;i >= 0;i--){
        cout << str[i];
        if(i != 0) cout << " ";
        else cout << endl;
    }
}