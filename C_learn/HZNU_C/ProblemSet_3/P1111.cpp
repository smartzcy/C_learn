#include<stdio.h>
using namespace std;
struct shijuan{
    double score;
    double time;
}shijuan[21];
int main(){
    int n , m;
    while (scanf("%d %d",&n,&m),n != 0){
        double dp[21][10001] = {{0}};
        for(int i = 1; i <= n ; i++){
            scanf("%lf %lf",&shijuan[i].time,&shijuan[i].score);
        }
        for(int i = 1; i <= n;i++){
            for(int j = 1; j <= m;j++){
                if(j < shijuan[i].time) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i - 1][j] > dp[i - 1][j - (int)shijuan[i].time] + shijuan[i].score?dp[i - 1][j] : dp[i - 1][j - (int)shijuan[i].time] + shijuan[i].score;
            }
        }
        printf("%.2f\n",dp[n][m]);
    }
    return 0;
}