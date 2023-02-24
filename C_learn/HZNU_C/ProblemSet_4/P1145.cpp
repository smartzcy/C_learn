#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int T;
    int num[300];
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        for(int i = 0 ;i < n;i++) cin >> num[i];
        sort(num,num + n);
        for(int i = 1 ; i <= num[n - 1];i++){
            int j;
            int flag[20000] = {0};
            int M = 0;
            for(j = 0 ; j < n ;j++){
                int m = num[j] % i;
                if(flag[m] == 1) break;
                flag[m] = 1;
            }
            if(j == n && M != 1){
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}