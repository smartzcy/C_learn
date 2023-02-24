#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int num[11];
int sum = 0;
bool isFlag(int n,int max){
    for(int i = 0;i < n;i++)
        if(num[i] == num[n] ||abs(num[i] - num[n]) == abs(n - i)) return false;
    return true;
}
void queen(int n , int max){
    for(int i = 0; i < max;i++){
        num[n] = i;
        if(isFlag(n,max))
            if(n == max - 1) sum++;
            else queen(n + 1,max);
    }
}
int main(){
    int n;
    while(cin >> n){
        memset(num,0,sizeof(num));
        sum = 0;
        queen(0,n);
        cout << sum << endl;
    }
}