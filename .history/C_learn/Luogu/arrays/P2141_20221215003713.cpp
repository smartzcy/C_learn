#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int num1[100];
    int num[10000];
    for(int i = 0 ; i < n;i++){
        cin >> num1[i];
        num[num1[i]] = 1;
    }
    int sum = 0;
    for(int i = 0 ; i < n;i++){
        for(int j = 0 ; j < n;j++){
            if(num1[i] != num1[j]) if(num[num1[i] + num1[j]] == 1) sum++;
        }
    }
    cout << sum / 2;
}