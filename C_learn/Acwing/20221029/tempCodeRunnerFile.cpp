#include<iostream>
using namespace std;
int main(){
    int num[50001];
    int n , r1 , r2;
    cin >> n >> r1 >> r2;
    for(int i = 1 ; i <= n;i++){
        if(i != r1){
            cin >> num[i];
        }
    }
    if(num[r2] == r1) num[r1] = r2;
    else {
        int m = r2 , nm = 0 , k;
        while(num[m] != r1){
            k = m;
            m = num[m];
            num[k] = nm;
            nm = k;
        }
        num[m] = nm;
        num[r1] = m;
    }
    for(int i = 1 ; i <= n;i++){
        if(i != r2) cout << num[i] << " ";
    }
}