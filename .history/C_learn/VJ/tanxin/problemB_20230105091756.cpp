#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n , m , num[10000] , ans = 0;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++) cin >> num[i];
    sort(num , num + n);
    int i = n - 1 , j = 0;
    while(j <= i){
        if(num[i] + num[j] > m){
            i--;
        }else{
            i--;
            j++;
        }
        ans++;
    }
    cout << ans << endl;
}