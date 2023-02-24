#include<stdio.h>
int main(){
    int n,m;
    int lang[20][20];
    while (scanf("%d %d",&n,&m) != EOF)
    {
        for(int i = 0;i < m;i++){
            int a,b;
            scanf("%d %d",&a,&b);
            scanf("%d",lang[a][b]);
            lang[b][a] = lang[a][b];
        }
        int x,y;
        scanf("%d %d",&x,&y);

    }
    
}