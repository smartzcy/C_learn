#include<iostream>
using namespace std;
int main(){
    string str , s = "PATest";
    int num[6] = {0};
    cin >> str;
    for(int i = 0 ; i < str.length();i++){
        if(str[i] == 'P') num[0]++;
        if(str[i] == 'A') num[1]++;
        if(str[i] == 'T') num[2]++;
        if(str[i] == 'e') num[3]++;
        if(str[i] == 's') num[4]++;
        if(str[i] == 't') num[5]++;
    }
    int n = 0;
    for(int i = 0 ; i < 6;i++){
        n += num[i];
    }
    int k = 0;
    while(n != 0){
        if(num[k] != 0) {
            cout << s[k];
            num[k]--;
            n--;
        }
        k++;
        k %= 6;
    }
    cout << endl;
    return 0;
}