#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
    int n;
    int k = 0;
    int num[10000];
    printf("从标准设备读入数据，直到输入是非整型数据为止\n");
    while (scanf("%d",&n) == 1){
        num[k++] = n;
    }
    sort(num,num + k);
    for(int i = 0 ; i < k;i++){
        printf(" %d",num[i]);
    }
    return 0;
}