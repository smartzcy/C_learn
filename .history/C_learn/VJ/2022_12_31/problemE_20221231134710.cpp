#include<iostream>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int n , k , ans = 0 , num = 0;
        cin >> n >> k;
        string str;
        cin >> str;
        for(int i = 0 ; i < n;i++){
            if(num != 0){
                ans += str[i] - '0';
                if(i == num) num += k;
            }else if(str[i] == '1') num = i + k;
        }
        cout << ans << endl;
    }
}