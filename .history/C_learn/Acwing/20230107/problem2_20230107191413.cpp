#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    string s;
    cin >> s;
    int k , w[27]  ,ans = 0;
    cin >> k;
    for(int i = 0 ; i < 26 ; i++){
        cin >> w[i];
    }
    for(int i = 0 ; i < s.size() ; i++){
        ans += (i + 1) * w[s[i] - 'a'];
    }
    sort(w , w + 26 , greater<int>());
    for(int i = s.size() ; i <= s.size() + k ; i++){
        ans += w[0] * i;
        cout << "1" << endl;
    }
    cout << ans << endl;
}