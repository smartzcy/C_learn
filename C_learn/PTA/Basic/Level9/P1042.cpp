#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    getline(cin,str);
    int num[26] = {0};
    for(int i = 0 ; i < str.length();i++){
        if(str[i] <= 'z' && str[i] >= 'a') num[str[i] - 'a']++;
        else if(str[i] <= 'Z' && str[i] >= 'A') num[str[i] - 'A']++;
    }
    int max = 0;
    for(int i = 1 ; i < 26;i++){
        if(num[max] < num[i]) max = i;
    }
    cout << (char)('a' + max) << " " << num[max] << endl;
}