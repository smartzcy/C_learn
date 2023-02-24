#include<iostream>
using namespace std;
int main(){
    int n , k = 0;
    cin >> n;
    int num[1000];
    while(n != 1){
        if(n % 2 == 0){
            n /= 2;
        }else{
            n = n * 3 + 1;
        }
        num[k++] = n;
    }
    for(int i = k - 1 ; i >= 0;i--){
        cout << num[i] << " ";
    }
}