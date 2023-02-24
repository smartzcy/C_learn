#include<iostream>
#include<string.h>
using namespace std;
int main(){
    string s[] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
    string s1;
    char str[101];
    cin >> str;
    int num = 0;
    for(int i = 0 ; i < strlen(str);i++){
        num += str[i] - '0';
    }
    while(num != 0){
        s1 += (num % 10) + '0';
        num /= 10;
    }
    for(int i = s1.length() - 1 ; i >= 0;i--){
        cout << s[s1[i] - '0'];
        if(i == 0) cout << endl;
        else cout << " ";
    }
}