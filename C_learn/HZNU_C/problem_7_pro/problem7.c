#include<stdio.h>
struct JieJu
{
    int love;
    int time;
};
int main(){
    int N,T;
    struct JieJu jieju[1001];
    while (scanf("%d %d",&N,&T),N != 0){
        int game = 0;
        int dp[1005][2000] = {{0}};
        while (N--)
        {
            int n;
            scanf("%d",&n);
            for(int i = 1; i <= n ; i++){
                scanf("%d",&jieju[game + i].love);
            }
            for (int i = 1; i <= n; i++){
                scanf("%d",&jieju[game + i].time);
            }
            game += n;
        }
        for(int i = 1; i <= game;i++){
            for(int j = 1; j <= T;j++){
                if(j < jieju[i].time) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i - 1][j] > dp[i - 1][j - jieju[i].time] + jieju[i].love?dp[i - 1][j] : dp[i - 1][j - jieju[i].time] + jieju[i].love;
            }
        }
        printf("%d\n",dp[game][T]);
    }
}