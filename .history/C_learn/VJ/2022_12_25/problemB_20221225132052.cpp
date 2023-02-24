#include <iostream>
#include <set>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        string str;
        cin >> str;
        if(str.find("a") != string::npos){
            int n = 1;
            int x = str.find("a");
            int i = x - 1;
            int j = x + 1;
            while(i >= 0 || j < str.length()){
                cout << i << " " << j << endl;
                if(i >= 0 && str[i] == (char)(n + 'a')){
                    i--;
                    n++;
                }else if(j < str.length() && str[j] == (char)(n + 'a')){
                    j++;
                    n++;
                }else{
                    cout << "NO" << endl;
                    break;
                }
            }
            if(i < 0 && j >= str.length()) cout << "YES" << endl;
        }else cout << "NO" << endl;
    }
    return 0;
}