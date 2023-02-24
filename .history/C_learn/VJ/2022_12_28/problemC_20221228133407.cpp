#include<iostream>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        string str;
        int ans = 0;
        cin >> str;
        for(int i = 0 ; i < str.length() ; i+=2){
            if(i == str.length() - 1){
                ans++;
                break;
            }
            if(str[i] != str[i + 1]){
                int j = i + 1;
                for(; j < str.length() ; j++){
                    if(str[i] == str[j]){
                        ans += j - i - 1;
                        i = j - 1;
                        break;
                    }
                }
                if(j == str.length()) {
                    ans++;
                    i--;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}