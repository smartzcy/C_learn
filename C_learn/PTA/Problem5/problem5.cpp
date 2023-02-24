#include<iostream>
using namespace std;
int main(){
    int cnt = 0;
    string s , name1 , name2;
    while(cin >> s && s != "."){
        cnt++;
        if(cnt == 2) name1 = s;
        if(cnt == 14) name2 = s;
    }
    if(cnt >= 14) cout << name1 << " and " << name2 << " are inviting you to dinner..." << endl;
    else if(cnt >= 2) cout << name1 << " is the only one for you..." << endl;
    else cout << "Momo... No one is for you ..." << endl;
}