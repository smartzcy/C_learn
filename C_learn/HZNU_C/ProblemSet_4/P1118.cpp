#include<stdio.h>
using namespace std;
int main(){
    char str1[26] = {'E','C','F','A','J','K','L','B','D','G','H','I','V','W','Z','Y','M','N','O','P','Q','R','S','T','U','X'};
    char str2[26] = {'e','r','w','q','t','y','g','h','b','n','u','i','o','p','s','j','k','d','l','f','a','z','x','c','v','m'};
    char ch;
    while (scanf("%c",&ch),ch != '#'){
        if(ch <= 'Z' && ch >= 'A'){
            printf("%c",str1[ch - 65]);
        }else if(ch <= 'z' && ch >= 'a'){
            printf("%c",str2[ch - 97]);
        }else{
            printf("%c",ch);
        }
    }
    return 0;
}