#include<stdio.h>
#include<math.h>
#include<string.h>
bool num[100000001];
using namespace std;
void ways(){
    memset(num,true,sizeof(num));
    num[1] = false;
    for(int i = 2 ; i <= sqrt(100000000) + 1;i++)
        for(int j = 2 ; j <= 100000000 / i;j++)
            num[i * j] = false;
}
int main(){
    ways();
    int n;
    while (scanf("%d",&n),n != 0){
        int count = 0;
        for(int i = 1 ; i <= n;i++) 
            count += num[i];
        printf("%d\n",count);
    }
    return 0;
}