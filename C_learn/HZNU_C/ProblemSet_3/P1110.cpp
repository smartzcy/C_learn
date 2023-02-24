#include<stdio.h>
using namespace std;
int ways(int n){
    if(n==1) return 1;
    else if(n==2) return 2;
    else if(n==3) return 4;
    return ways(n - 1) + ways(n - 2) + ways(n - 3);
}
int main(){
    int n;
    while (scanf("%d",&n),n != 0){
        printf("%d\n",ways(n));
    }
    return 0;
}