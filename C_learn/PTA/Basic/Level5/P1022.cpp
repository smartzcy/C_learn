#include<iostream>
using namespace std;
int main(){
    string str;
    int A , B , D;
    cin >> A >> B >> D;
    int num = A + B;
    if(num == 0) str = "0";
    while(num != 0){
        str += '0' + num % D;
        num /= D;
    }
    for(int i = str.length() - 1 ; i >= 0;i--){
        cout << str[i];
    }
    cout << endl;
}