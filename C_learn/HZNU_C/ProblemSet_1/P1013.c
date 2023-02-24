#include<stdio.h>
int main(){
    int k = 0;
    int n,m;
    while (scanf("%d %d",&n,&m), n != 0)
    {   
        k++;
        char str[102][102];
        for(int i = 1;i <= n;i++){
            getchar();
            for(int j =1; j <= m;j++){
                char ch;
                scanf("%c",&ch);
                if(ch == '*'){
                    str[i][j] = ch;
                }else{
                    str[i][j] = '0';
                }
            }
        }
        for(int i = 1; i <= n;i++){
            for(int j = 1 ; j <= m;j++){
                if(str[i][j] != '*'){
                    int count = 0;
                    if (str[i - 1][j - 1] == '*')
                        count++;
                    if (str[i - 1][j] == '*')
                        count++;	
                    if (str[i - 1][j + 1] == '*')
                        count++;
                    if (str[i][j - 1] == '*')
                        count++;	
                    if (str[i][j + 1] == '*')
                        count++;	
                    if (str[i + 1][j - 1] == '*')
                        count++;	
                    if (str[i + 1][j] == '*')
                        count++;	
                    if (str[i + 1][j + 1] == '*')
                        count++;
                    str[i][j] = count + '0';
                }
            }
        }
        printf("Field #%d:\n",k);
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                printf("%c",str[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    
}