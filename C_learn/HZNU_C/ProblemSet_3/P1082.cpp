// #include<stdio.h>
// using namespace std;
// int main(){
//     int N;
//     while (~scanf("%d",&N)){
//         int num1[1000],num2[1000];
//         num1[0] = 1;
//         num2[0] = 2;
//         int n1 = 0 , n2 = 0;
//         for(int i = 0 ; i < N ;i++){
//             int n , m;
//             scanf("%d %d",&n,&m);
//             if(num1[n1] == n) num1[++n1] = m;
//             else if(num2[n2] == n) num2[++n2] = m;
//         }
//         if(n2 > n1) printf("You are my younger\n");
//         else if(n2 < n1) printf("You are my elder\n");
//         else printf("You are my brother\n");
//     }
//     return 0;
// }
#include<iostream>
using namespace std;
int main() {
    int n, a, b;
    while(cin >> n) {
        int num[2100] = {0};
        for (int i=0; i<n; i++) {
            cin >> a >> b;
            num[a] = b;
        }
        int num1 = 0, num2 = 0;
        for (int i = 1; num[i] != 0; i = num[i]) num1++;
        for (int i = 2; num[i] != 0; i = num[i]) num2++;
        if (num1 < num2) cout << "You are my younger" << endl;
        else if (num1 > num2) cout << "You are my elder" << endl;
        else cout << "You are my brother" << endl;
    }
    return 0;
}