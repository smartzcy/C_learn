#include<iostream>
#include<array>
#include<algorithm>
using namespace std;
int n , m , f[10000];
void INIT(){
    for(int i = 1; i <= n;i++) f[i] = i;
}
int find(int x){
    return f[x] == x ? x : f[x] = find(f[x]);
}
void merge(int x , int y){
    int fx = find(x);
    int fy = find(y);
    f[fx] = fy;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
}