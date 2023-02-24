#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
#define MAXN 100001
#define MAXL 200001
int prime[MAXN];
bool check[MAXL];
void way(int n){
    check[1] = 1;
    int count = 0;
    memset(check, 0, sizeof(check));
    for (int i = 2; i <= n; i++)
    {
        if (!check[i])
            prime[count++] = i;
        for (int j = 0; j < count; j++)
        {
            if (i*prime[j] > MAXL)
                break;
            check[i*prime[j]] = 1;
            if ( (i%prime[j]) == 0 )
                break;
        }
    }
}
int main(){
    int n , q;
    cin >> n >> q;
    way(n);
    while(q--){
        int l , r;
        cin >> l >> r;
        int max1 = INT_MIN;
        int num = 0;
        for(int i = l ; i <= r;i++){
            if(check[i]){
                num++;
            }else if(!check[i]){
                max1 = max(max1,num);
                num = 0;
            }
            if(i == r){
                max1 = max(max1,num);
                num = 0;
            }
        }
        cout << max1 << endl;
    }
}

