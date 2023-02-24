#include<stdio.h>
using namespace std;
int num[62] = {0};
void innet(){
    int n = 2;
    for(int i = 0 ; i < 62;i += (n++)){
        num[i] = 1;
    }
}
int main(){
    int n , m;
    innet();
    while (scanf("%d/%d",&n,&m),n != 0 && m != 0){
        if(n > 8) printf("0\n");
        else if(n < 7){
            int count = 0;
            for(int i = 0 ; i < 62;i++){
                if(num[i] == 1)  count++;
            }
            printf("%d",count);
        }else {
            int num1 = n / 8 * 31 + m - 1;
            int count = 0;
            for(int i = num1 ; i < 62;i++){
                if(num[i] == 1) count++;
            }
            printf("%d\n",count);
        }
    }
    return 0;
}