#include<stdio.h>
#include<string.h>
struct Student
{
    char name[51];
    int score;
};

int main(){
    struct Student student[1000];
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i = 0; i < n; i++){
            scanf("%s %d",student[i].name,&student[i].score);
        }
        int m;
        scanf("%d",&m);
        getchar();
        for(int i = 0;i < m;i++){
            char name1[51];
            gets(name1);
            int k = 0;
            for(int j = 0; j < n;j++){
                if(strcmp(name1,student[j].name) == 0){
                    printf("%d\n",student[j].score);
                    k = 1;
                    break;
                }
            }
            if(k == 0) printf("error\n");
        }
    }
    
}