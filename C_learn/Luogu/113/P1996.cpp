#include<iostream>
using namespace std;
int main(){
    int n , m;
    cin >> n >> m;
    int num[101];
    for(int i = 1; i <= n;i++){
        num[i] = i;
    }
    int num1 = 0;
    int k = 1;
    int i = 1;
    while(num1 != n){
        if(num[i] != 0){
            if(k % m == 0){
                cout << i << " ";
                num[i] = 0;
                num1++;
            }
            k++;
        }
        if(i == n) i = 0;
        i++;
    }
    return 0;
}