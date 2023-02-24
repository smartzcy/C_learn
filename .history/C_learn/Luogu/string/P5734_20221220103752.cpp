#include <iostream>
using namespace std;
int main(){
    int q;
    cin >> q;
    string str;
    cin >> str;
    while(q--){
        int n;
        cin >> n;
        if(n == 1){
            string s;
            cin >> s;
            str += s;
            cout << str << endl;
        }else if(n == 2){
            int a , b;
            cin >> a >> b;
            str = str.substr(a , b);
            cout << str << endl;
        }else if(n == 3){
            int a;
            string s;
            cin >> a >> s;
            str = str.substr(0 , a) + s + str.substr(a);
            cout << str << endl;
        }else if(n == 4){
            string s;
            cin >> s;
            if(str.find(s) != string::npos) cout <<str.find(s) << endl;
            else cout << -1 << endl;
        }
    }
    return 0;
}