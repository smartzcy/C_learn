#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    char ch;
    int num = 0;
    while(~scanf("%c",&ch)){
        if(num == 0 && ch != '\"'){
            cout << ch;
        }else if(ch == '\"'){
            if(num == 0){
                num = 1;
            }else{
                num = 0;
            }
            cout << ch;
        }
    }
    return 0;
}