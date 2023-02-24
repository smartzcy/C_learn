#include<iostream>
using namespace std;
int main(){
    int n;
    while (cin >> n,n != 0){
        int na[20001] = {0};
        int number = 0;
        for(int i = 0 ; i < 2 * n;i++){
            int m;
            cin >> m;
            na[i + 1] = na[i] + m;
            number += m;
        }
        int count = 0;
        for(int i = 1 ; i <= 2 * n;i++){
            int nu  = number - na[i - 1];
            for(int j = 1 ;j <= 2 * n;j++){
                if(na[j] == nu) count++;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}