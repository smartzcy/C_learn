#include<stdio.h>
struct List
{
    int id;
    char str[21];
};

int main(){
    int T,N;
    struct List list1[10000];
    int nums[10000];
    scanf("%d %d", &T,&N);
    for(int i = 0; i < T; i++){
        scanf("%d %s",&list1[i].id,&list1[i].str);
    }
    for(int i = 0; i < N; i++){
        scanf("%d",&nums[i]);
    }
    for(int i = 0; i < N;i++){
        for(int j = 0; j < T;j++){
            if(nums[i] == list1[j].id){
                if(i != N - 1){
                    printf("%s ",list1[j].str);
                }else{
                    printf("%s",list1[j].str);
                }
                break;
            }
        }
    }
}