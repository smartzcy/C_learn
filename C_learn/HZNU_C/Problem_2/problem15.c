#include<stdio.h>
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int num[100][100];
    int min[100];
    int max[100];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&num[i][j]);
            if(min[i] == 0 || min[i] > num[i][j]){
                min[i] = num[i][j];
            }
            if(max[j] == 0 || max[j] < num[i][j]){
                max[j] = num[i][j];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(min[i] == max[j]){
                printf("(%d,%d)",i+1,j+1);
                break;
            }
        }
    }
}