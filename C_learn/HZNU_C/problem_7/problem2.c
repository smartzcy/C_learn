#include<stdio.h>
#include<string.h>
struct Student
{
    char zkzh[9];
    char name[15];
    int cj;
};
int main(){
    struct Student student[20];
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0;i < n;i++){
        scanf("%s %s %d",&student[i].zkzh,&student[i].name,&student[i].cj);
    }
    for(int i = 0;i < m;i++){
        char str[9];
        scanf("%s",&str);
        for(int j = 0;j < n;j++){
            if(strcmp(str,student[j].zkzh) == 0){
                if(student[j].cj >= 90){
                    printf("A\n");
                }else if (student[j].cj >= 80){
                    printf("B\n");
                }else if (student[j].cj >= 70){
                    printf("C\n");
                }else if (student[j].cj >= 60){
                    printf("OK\n");
                }else{
                    printf("ARE YOU PIG?\n");
                }
            }
        }
    }
}