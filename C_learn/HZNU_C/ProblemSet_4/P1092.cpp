#include<iostream>
using namespace std;
int num1[1001] = {0};
int num2[1001] = {0};
void print(int n){
    if(n == 1 || n == 2){
        cout << 1;
        return;
    }
    num1[1000] = 1;
    num2[1000] = 1;
    for(int i = 3;i <= n;i++){
        
    }
}
int main(){
    int n;
    cin >> n;
    print(n);
}