#include<iostream>
using namespace std;
int main(){
    int n , k , x;
    cin >> n >> k >> x;
    int num[100][100];
    for(int i = 0 ; i < n;i++){
        for(int j = 0 ; j < n; j++){
            cin >> num[i][j];
        }
    }
    int m = 1;
    for(int i = 0 ; i < n / 2 ; i++){
        for(int j = n - 1 ; j >= 0; j--){
            if(j >= m){
                num[j][i * 2 + 1] = num[j - m][i * 2 + 1];
            }else{
                num[j][i * 2 + 1] = x;
            }
        }
        if(m == k){
            m = 1;
        }else{
            m++;
        }
    }
    for(int i = 0 ; i < n ; i++){
        int sum = 0;
        for(int j = 0 ; j < n ; j++){
            sum += num[i][j];
        }
        if(i != n - 1){
            printf("%d ",sum);
        }else{
            printf("%d",sum);
        }
    }
    // for(int i = 0 ; i < n; i++){
    //     for(int j = 0 ;j < n;j++){
    //         printf("%d ",num[i][j]);
    //     }
    //     printf("\n");
    // }
}