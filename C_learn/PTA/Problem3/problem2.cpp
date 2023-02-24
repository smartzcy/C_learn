#include<iostream>
#include<string.h>
using namespace std;
int main(){
    int num[4] = {0};
    char str[10000];
    char ch[] = {"GPLT"};
    cin >> str;
    for(int i = 0 ; i < strlen(str);i++){
        if(str[i] == 'G' || str[i] == 'g') num[0]++;
        else if(str[i] == 'P' || str[i] == 'p') num[1]++;
        else if(str[i] == 'L' || str[i] == 'l') num[2]++;
        else if(str[i] == 'T' || str[i] == 't') num[3]++;
    }
    int k = 0;
    while(num[0] != 0 || num[1] != 0 || num[2] != 0 || num[3] != 0){
        if(num[k] != 0) {
            cout << ch[k];
            num[k]--;
        }
        k++;
        k = k % 4;
    }
}