#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    int num1[1010],num2[1010];
    while (cin >> n,n != 0){
        int count = 0;
        for(int i = 0 ; i < n;i++) cin >> num1[i];
        for(int i = 0 ; i < n;i++) cin >> num2[i];
        sort(num1,num1 + n);
        sort(num2,num2 + n);
        for(int i = n - 1;i >= 0 ;i--){
            for(int j = n - 1 ;j >= 0;j--){
                if(num1[i] > num2[j] && num2[j] != 0){
                    num2[j] = 0;
                    count++;
                    break;
                }
            }
        }
        if(n - count < count)printf("YES\n");
        else printf("NO\n");
    }
    
}