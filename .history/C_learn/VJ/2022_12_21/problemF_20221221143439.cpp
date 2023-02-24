#include<iostream>
using namespace std;
int mod = 1e9 + 7;
int main(){
    int n ,c = 0 , d = 0;
    long long ans = 0;
    int x = 0 , z = 0;
    string s;
    cin >> n >> s;
    for(int i = 0 ; i < n;i++){
        if(s[i] == 'c') c++;
        else if(s[i] == '?') d++;
    }
    for(int i = 0 ; i < n;i++){
        if(s[i] == 'a'){
            x++;
        }else if(s[i] == 'b'){
            ans += (x + z) * (c + d);
        }else if(s[i] == 'c'){
            c--;
        }else if(s[i] == '?'){
            d--;
            ans += (x + z) * (c + d);
            z++;
        }
    }
    cout << ans << endl;
}