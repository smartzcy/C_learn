#include<iostream>
using namespace std;
int mod = 1e9 + 7;
int main(){
    int n , a = 0 , b = 0 , c = 0 , d = 0;
    long long ans = 0;
    int x = 0 , y = 0 , z = 0 , k = 0;
    string s;
    cin >> n >> s;
    for(int i = 0 ; i < n;i++){
        if(s[i] == 'a') a++;
        else if(s[i] == 'b') b++;
        else if(s[i] == 'c') c++;
        else if(s[i] == '?') d++;
    }
    for(int i = 0 ; i < n;i++){
        if(s[i] == 'a'){
            x++;
            a--;
        }else if(s[i] == 'b'){
            b--;
            k++;
            ans += (x + z) * (c + d);
        }else if(s[i] == 'c'){
            y++;
            c--;
        }else if(s[i] == '?'){
            d--;
            ans += (b + d) * c + b * (c + d);
            ans += (x + z) * (c + d);
            ans += (x + z) * k + x * (k + z);
            z++;
        }
    }
    cout << ans << endl;
}