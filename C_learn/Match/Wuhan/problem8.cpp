#include<iostream>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        long long num[4];
        for(int i=1; i<=3; i++)cin >> num[i];
        int n;
        cin >> n;
        long long x = 0 , y = 0;
        int flag = 0;
        for(int i = 1 ; i<=3; i++){
            if(i != n){
                if(flag == 0) x = num[i];
                else y = num[i];
                flag = 1;
            }
        }
        if(x == y || abs(x - y) % 3 == 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}