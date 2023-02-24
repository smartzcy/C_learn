#include<iostream>
using namespace std;
void Print(string pre , string inor){
    if(pre.empty()) return;
    char ch = pre[0];
    int k = inor.find(ch);
    pre.erase(pre.begin());
    string left1 = pre.substr(0 , k);
    string right1 = pre.substr(k);
    string left2 = inor.substr(0 , k);
    string right2 = inor.substr(k + 1);
    Print(left1 , left2);
    Print(right1 , right2);
    cout << ch;
}
int main(){
    string s1 , s2;
    cin >> s1 >> s2;
    Print(s1 , s2);
    return 0;
}