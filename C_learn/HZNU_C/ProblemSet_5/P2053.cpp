#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int num[2000000];
    for(int i = 0 ; i < n;i++)
        cin >> num[i];
    sort(num,num + n);
    for(int i = 0 ; i < n; i++){
        if(i == 0) cout << num[i];
        else cout << " " << num[i];
    }
    cout << endl;
    int m;
    cin >> m;
    while(m--){
        int num1;
        cin >> num1;
        int *index;
        index = find(num,num + n,num1);
        int *i;
        for(i = index + 1; i < num + n;i++)
            if(*i != *(i - 1)) break;
        cout << i - num << endl;
    }
}
// #include<iostream>
// #include<stdio.h>
// #include<algorithm>
// using namespace std;
// int main(){
//     int n;
//     scanf("%d",&n);
//     int num[2000000];
//     for(int i = 0 ; i < n;i++)
//         scanf("%d",&num[i]);
//     sort(num,num + n);
//     for(int i = 0 ; i < n; i++){
//         if(i == 0) printf("%d",num[i]);
//         else printf(" %d",num[i]);
//     }
//     printf("\n");
//     int m;
//     scanf("%d",&m);
//     while(m--){
//         int num1;
//         scanf("%d",&num1);
//         int i = 0;
//         int j = n - 1;
//         while(i <= j){
//             int mid = (i + j) / 2;
//             if(num[mid] > num1){
//                 j = mid - 1;
//             }else{
//                 i = mid + 1;
//             }
//         }
//         printf("%d\n",i);
//     }
//     return 0;
// }