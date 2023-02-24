// #include<stdio.h>
// #include<algorithm>
// using namespace std;
// int main(){
//     int N , M;
//     while (~scanf("%d %d",&N,&M)){
//         int num[100001];
//         for(int i = 0 ; i < N;i++) scanf("%d",&num[i]);
//         sort(num,num + N);
//         int sum;
//         int i;
//         for(i = num[N - 1] - 1;i >= 0;i--){
//             sum = 0;
//             for(int j = N - 1;j >= 0;j--){
//                 if(num[j] - i > 0) sum += (num[j] - i);
//             }
//             if(sum >= M) break;
//         }
//         printf("%d\n",i);
//     }
//     return 0;
// }
#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
    int N , M;
    while (~scanf("%d %d",&N,&M)){
        int num[100001];
        for(int i = 1 ; i <= N;i++) scanf("%d",&num[i]);
        sort(num + 1,num + N + 1);
        int sum = 0;
        int i;
        for(i = N - 1;i >= 1;i--){
            int num1 = (num[i + 1] - num[i]) * (N - i);
            if(num1 + sum >= M)break;
            sum += num1;
        }
        int n = (M - sum) / (N - i) + ((M - sum) % (N - i) == 0?0:1);
        printf("%d\n",num[i + 1] - n);
    }
    return 0;
}