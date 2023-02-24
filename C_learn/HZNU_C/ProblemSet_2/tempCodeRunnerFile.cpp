#include<stdio.h>
using namespace std;
int main(){
    int n , m;
    while (~scanf("%d %d",&n,&m)){
        int direction[21][21];
        for(int i = 1; i <= n;i++){
            for(int j = 1; j <= n;j++){
                if(j == i) direction[i][j] = 0;
                else direction[i][j] = 1000000001;
            }
        }
        for(int i = 1;i <= m;i++){
            int a , b , c;
            scanf("%d %d %d",&a,&b,&c);
            direction[a][b] = c;
            direction[b][a] = c;
        }
        for(int k = 1;k <= n;k++){
            for(int i = 1;i <= n;i++){
                for(int j = 1;j <= n;j++){
                    if(direction[i][k] + direction[k][j] < direction[i][j]){
                        direction[i][j] = direction[i][k] + direction[k][j];
                    }
                }
            }
        }
        int x , y;
        scanf("%d %d",&x,&y);
        if(direction[x][y] != 1000000001) printf("%d\n",direction[x][y]);
        else printf("No path\n");
        // for(int i = 1; i <= n;i++){
        //     for(int j = 1;j <= n;j++){
        //         printf("%d ",direction[i][j]);
        //     }
        //     printf("\n");
        // }
    }
    return 0;
}