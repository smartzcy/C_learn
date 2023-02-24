#include<stdio.h>
#include<string.h>
using namespace std;
int main(){
    char str[101];
    while (~scanf("%s", str)){
        for(int i = 0 ; i < strlen(str);i++){
            if(str[i] <= 'Z' && str[i] >= 'A'){
                str[i] = (str[i] + 1 - 65) % 26 + 97;
            }else if(str[i] < 'y' && str[i] >= 'a'){
                if(str[i] == 's')str[i] = '7';
                else if(str[i] == 'v')str[i] = '8';
                else str[i] = (str[i] - 97) / 3 + 50;
            }else if (str[i] == 'z' || str[i] == 'y'){
                str[i] = '9';
            }
        }
        printf("%s\n",str);
    }
    return 0;
}