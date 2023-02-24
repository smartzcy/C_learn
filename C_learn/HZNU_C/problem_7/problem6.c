#include<stdio.h>
struct BiaoQian
{
    int num;
    int n1;
    int n2;
};
int main(){
    struct BiaoQian biaoqian[100];
    int mins[100];
    int maxs[100];
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d",&biaoqian[i].num,&biaoqian[i].n1,&biaoqian[i].n2);
        mins[i] = 0;
        maxs[i] = 0;
    }
    int min;
    int max;
    for(int i = 1;i <= 10;i++){
        min = 0;
        max = 0;
        for(int j = 1; j < n;j++){
            if(biaoqian[min].n1 > biaoqian[j].n1 && mins[j] == 0 || mins[min] == 1) min = j;
            if(biaoqian[max].n2 < biaoqian[j].n2 && maxs[j] == 0 || maxs[max] == 1) max = j;
        }
        mins[min] = 1;
        maxs[max] = 1;
    }
    printf("%d %d",biaoqian[min].num,biaoqian[max].num);
}