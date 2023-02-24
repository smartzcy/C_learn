#include<stdio.h>
#include<string.h>
int main(){
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        char str[10][200];
        getchar();
        for(int i = 0; i < n; i++){
            gets(str[i]);
        }
        for(int i = 0;i < m; i++){
            char a;
            int n1 , n2;
            scanf("%c %d %d",&a,&n1,&n2);
            getchar();
            if(a == 'A'){
                strcat(str[n1 - 1],str[n2 - 1]);
            }else if(a == 'C'){
                strcpy(str[n1 - 1],str[n2 - 1]);
            }
        }
        printf("%s\n",str[0]);
    }
}