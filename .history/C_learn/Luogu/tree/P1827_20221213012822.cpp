#include<iostream>
using namespace std;
void Print(string pre , string inor){
    if(pre == "") return;
    char ch = pre[0];
    int k = inor.find(ch);
    string left1 = pre.substr(1 , k + 1);
    string right1 = pre.substr(k + 1);
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