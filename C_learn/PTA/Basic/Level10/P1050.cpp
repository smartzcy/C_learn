// #include<iostream>
// #include<algorithm>
// #include<math.h>
// using namespace std;
// int main(){
//     int n;
//     cin >> n;
//     int num[10000];
//     for(int i = 0 ; i < n;i++){
//         cin >> num[i];
//     }
//     sort(num,num + n);
//     int sum[1001][102];
//     int k = n - 1;
//     int i = 0 , j = 0;
//     int nm,m;
//     for(m=(int)sqrt(n*1.0);m>0;m--){
//         if(n%m==0)break;
//     }
//     nm=n/m;
//     cout << m << " " << nm << endl;
//     int flag = 1;
//     int a1 = 0 , a2 = m - 1, b1 = 1 , b2 = nm - 1;
//     while(k >= 0){
//         sum[i][j] = num[k--];
//         if(j == a2 && flag == 1){
//             flag = 2;
//             a2--;
//         }else if(j == a1 && flag == 3){
//             flag = 4;
//             a1++;
//         }else if(i == b2 && flag == 2){
//             flag = 3;
//             b2--;
//         }else if(i == b1 && flag == 4){
//             flag = 1;
//             b1++;
//         }
//         if(flag == 1) j++;
//         else if(flag == 2) i++;
//         else if(flag == 3) j--;
//         else if(flag == 4) i--;
//     }
//     for(int i = 0 ; i < nm;i++){
//         for(int j = 0 ; j < m ;j++){
//             cout << sum[i][j];
//             if(j != m - 1) cout << " ";
//             else cout << endl;
//         }
//     }
// }

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int cmp(int a, int b) {return a > b;}
int main() {
    int N, m, n, t = 0;
    scanf("%d", &N);
    for (n = sqrt((double)N); n >= 1; n--) {
        if (N % n == 0) {
            m = N / n;
            break;
        }
    }
    vector<int> a(N);
    for (int i = 0; i < N; i++)
        scanf("%d", &a[i]);
    sort(a.begin(), a.end(), cmp);
    vector<vector<int> > b(m, vector<int>(n));
    int level = m / 2 + m % 2;
    for (int i = 0; i < level; i++) {
        for (int j = i; j <= n - 1 - i && t <= N - 1; j++)
                b[i][j] = a[t++];
        for (int j = i + 1; j <= m - 2 - i && t <= N - 1; j++)
                b[j][n - 1 - i] = a[t++];
        for (int j = n - i - 1; j >= i && t <= N - 1; j--)
                b[m - 1 - i][j] = a[t++];
        for (int j = m - 2 - i; j >= i + 1 && t <= N - 1; j--)
                b[j][i] = a[t++];
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0 ; j < n; j++) {
            printf("%d", b[i][j]);
            if (j != n - 1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
