#include<iostream>
using namespace std;
int main(){
    int n , k = 1;
    cin >> n;
    int num[10000];
    num[0] = n;
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