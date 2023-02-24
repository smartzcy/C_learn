#include<iostream>
using namespace std;
int main(){
    int n;
    while(cin >> n){
        int num[1000];
        int f[1000];
        for(int i=0; i<n; i++){
            scanf("%d",&num[i]);
            f[i] = 1;
        }
        int x = 1;
        for(int i=0; i<n; i++){
            for(int j = 0; j<i; j++)
                if(num[j] < num[i]) f[i] = (f[i] > f[j] + 1? f[i]:f[j] + 1);
            x = (x > f[i]? x : f[i]);
        }   
        printf("%d\n", x);
    }
    return 0;
}