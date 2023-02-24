#include<stdio.h>
struct People
{
    char name[11];
    char birthday[12];
    char xb;
    char guding[17];
    char telegram[17];
};

int main(){
    struct People people[11];
    int n;
    scanf("%d",&n);
    for(int i = 0 ; i < n;i++){
        scanf("%s %s %c %s %s",people[i].name,people[i].birthday,&people[i].xb,people[i].guding,people[i].telegram);
    }
    scanf("%d",&n);
    for(int i = 1 ;i <= n;i++){
        int num;
        scanf("%d",&num);
        if(n > num){
            printf("%s %s %s %c %s\n",people[num].name,people[num].guding,people[num].telegram,people[num].xb,people[num].birthday);
        }else{
            printf("Not Found\n");
        }
    }
    return 0;
}