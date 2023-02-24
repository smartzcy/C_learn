#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int num[200001];
    int max1[200001];
    int n , q;
    cin >> n >> q;
    for(int i = 0 ; i <= q;i++) num[i] = i;
    for(int i = 0 ; i < n;i++){
        int a , b;
        cin >> a >> b;
        if(a == 1){
            for(int j = 0 ; j <= q;j++){
                num[j] &= b;
                if(j != 0) max1[j] = num[max1[j - 1]] > num[j] ? max1[j - 1] : j;
            }
        }else if(a == 2){
            for(int j = 0 ; j <= q ;j++){
                num[j] |= b;
                if(j != 0) max1[j] = num[max1[j - 1]] > num[j] ? max1[j - 1] : j;
            }
        }else if(a == 3){
            for(int j = 0 ; j <= q ; j++){
                num[j] ^= b;
                if(j != 0) max1[j] = num[max1[j - 1]] > num[j] ? max1[j - 1] : j;
            }
        }
    }
    for(int i = 0 ; i < q;i++){
        int a;
        cin >> a;
        cout << max1[a];
    }
}