#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        long long num[200001];
        cin >> n;
        for(int i = 0 ; i < n;i++){
            cin >> num[i];
        }
        sort(num,num + n);
        long long max = 0;
        for(int x = 0 ; x < n - 2;x++){
            for(int y = x + 1; y < n - 1;y++){
                max = max > 2 * num[y + 1] - num[x] - num[y] ? max : 2 * num[y + 1] - num[x] - num[y];
            }
        }
        cout << max << endl;
    }
    return 0;
}