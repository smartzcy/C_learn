#include<iostream>
using namespace std;
int main(){
    int n , m , k;
    cin >> n >> m >> k;
    int num[2001];
    for(int i = 1 ; i <= 2 * n ;i++){
        num[i] = i;
    }
    int a = 1 , b = n + 1;
    for(int i = 1 ; i <= k / m;i++){
        if((i * m) % n == 0){
            a = n;
            b = 2 * n;
        }else{
            a = (i * m) % n;
            b = (i * m) % n + n;
        }
        int k = num[a];
        num[a] = num[b];
        num[b] = k;
    }
    for(int i = 1 ; i <= 2 * n;i++){
        cout << num[i] << " ";
    }
}