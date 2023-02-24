#include<iostream>
#include<set>
using namespace std;
int main(){
    int n;
    multiset<string> s;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        string str;
        cin >> str;
        if(s.find(str) != s.end()){
            cout << str + "1" << endl;
        }else {
            s.insert(str);
            cout << "OK" << endl;
        }
    }
}