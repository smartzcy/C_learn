// #include<stdio.h>
// using namespace std;
// int main(){
//     int N;
//     int max = 0;
//     scanf("%d",&N);
//     int num1[201] = {0};
//     for(int i = 1; i <= N ; i++){
//         int n,m;
//         scanf("%d %d",&n,&m);
//         max = max < m ? m : max;
//         for(int j = n ; j < m;j++) num1[j] = 1;
//     }
//     scanf("%d",&N);
//     int num2[201] = {0};
//     for(int i = 1; i <= N ; i++){
//         int n,m;
//         scanf("%d %d",&n,&m);
//         max = max < m ? m : max;
//         for(int j = n ; j < m;j++) num2[j] = 1;
//     }
//     int cout = 0;
//     for(int i = 1 ; i < max;i++)
//         if(num1[i] == 1 && num2[i] == 1) cout++;
//     printf("%.3f",(double)cout);
// }

// #include<stdio.h>
// using namespace std;
// int main(){
//     double num[10000];
//     int N , M;
//     scanf("%d",&N);
//     for(int i = 1; i <= 2 * N;i++) scanf("%lf",&num[i]);
//     scanf("%d",&M);
//     double sum = 0;
//     for(int i = 1 ; i <= M; i++){
//         double x , y;
//         scanf("%lf %lf",&x,&y);
//         for(int j = 1 ; j <= N; j++){
//             if(x >= num[j * 2 - 1] && y <= num[j * 2]) sum += y - x;
//             else if(x >= num[j * 2 - 1] && y >= num[j * 2] && x <= num[j * 2]) sum += num[j * 2] - x;
//             else if(x <= num[j * 2 - 1] && y >= num[j * 2 - 1] && y <=num[j * 2]) sum += y - num[j * 2 - 1];
//             else if(x <= num[j * 2 - 1] && y >= num[j * 2]) sum += num[j * 2] - num[j * 2 - 1];
//         }
//     }
//     printf("%.3f",sum);
//     return 0;
// }

#include<stdio.h>
#include<algorithm>
using namespace std;
int main() {
    double a[210],b[210],ans = 0;
    int n,m;
    scanf("%d",&n);
    for(int i=1; i<=2*n; i++) scanf("%lf",&a[i]);
    scanf("%d",&m);
    for(int i=1; i<=2*m; i++) scanf("%lf",&b[i]);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            double s = min(a[i * 2], b[j * 2]) - max(a[i * 2 - 1], b[j * 2 - 1]);
            ans += max(0.0 , s);
        }
    }
    printf("%.3f",ans);
}
