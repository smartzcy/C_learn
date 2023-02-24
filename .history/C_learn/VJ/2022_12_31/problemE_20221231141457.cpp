#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int n , k , ans = 0 , num = 0 , cnt = 0;
        cin >> n >> k;
        string str;
        cin >> str;
        for(int i = 0 ; i < str.length() ; i++){
            if(str[i] == '1'){
                cnt++;
                n = i;
            }
        }
        for(int i = 0 ; i <= n;i++){
            if(num != 0){
                if(i == num){
                    if(str[i] == '0') ans++;
                    num += k;
                }else{
                    ans += str[i] - '0';
                }
            }else if(str[i] == '1') num = i + k;
        }
        cout << min(ans , cnt) << endl;
    }
    return 0;
}