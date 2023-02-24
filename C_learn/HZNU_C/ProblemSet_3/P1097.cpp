#include<iostream>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int N;
        cin >> N;
        if(N % 2 == 1){
            printf("0 0\n");
        }else{
            int min = 0;
            int max = 0;
            if(N % 2 == 0) max = N / 2;
            if(N % 4 == 0){
                min = N / 4;
            }else{
                min = N / 4 + 1;
            }
            printf("%d %d\n",min,max);
        }
    }
    return 0;
}