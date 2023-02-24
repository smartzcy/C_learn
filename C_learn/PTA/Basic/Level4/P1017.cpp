#include<iostream>
#include<string>
using namespace std;
int main(){
    string A , B;
    int b;
    cin >> A >> b;
    int num = 0;
    if(A.length() == 1 && A[0] - '0' < b) B = "0";
    for(int i = 0 ; i < A.length();i++){
        num = num *10 + (A[i] - '0');
        if(i != 0 || num / b != 0){
            B += to_string(num / b);
            num %= b;
        }
    }
    cout << B << " " << num << endl;
}