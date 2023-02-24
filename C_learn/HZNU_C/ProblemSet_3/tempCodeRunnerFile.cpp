#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    while (T--){
        int n;
        scanf("%d",&n);
        int num[10];
        int sum = 0;
        for(int i = 0 ; i < n ; i++){
            scanf("%d",&num[i]);
            if(num[i] > 0) sum += num[i];
        }
        sort(num,num + n);
        int i;
        int j = 0;
        for(i = 0 ; i < n;i++){
            if(0 < num[i]) break;
            if(num[i] < 0) j = i;
        }
        if(num[i] == 0 && i == n) i -= 2;
        else if(num[i] == 0) i++;
        if(num[j] == 0) j++;
        if(sum != 0){
            if(num[j] < 0)
                sum = sum - num[i] > sum + num[j] ? sum - num[i] : sum + num[j];
            else 
                sum = sum - num[i];
        }else{
            sum = num[j - 1];
        }
        printf("%d\n",sum);
    }
    return 0;
}