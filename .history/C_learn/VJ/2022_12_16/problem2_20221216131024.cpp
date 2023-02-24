#include <iostream>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int n , flag = 0;
        cin >> n;
        string s1 , s2;
        cin >> s1 >> s2;
        for(int i = 0 ; i < n ; i++){
            if(s1[i] != s2[i] && (s1[i] == 'G' && s2[i] != 'B' || s1[i] == 'B' && s2[i] != 'G')) flag = 1;
        }
        if(flag == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}