#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    string str[20];
    cin >> n;
    for(int i = 0 ; i < n;i++){
        cin >> str[i];
    }
    sort(str , str + n);
    for(int i = 0 ; i < n; i++) cout << str[i] << endl;
}