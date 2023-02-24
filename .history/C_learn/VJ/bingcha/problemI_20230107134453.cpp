#include<iostream>
using namespace std;
int n , f[100000];
int find(int x){
    return x == f[x] ? x : f[x] = find(f[x]);
}
void INIT(){
    for(int i = 1 ; i <= n ; i++){
        f[i] = i;
    }
}
void merge(int x , int y){
    int fx = find(x);
    int fy = find(y);
    f[fx] = fy;
}
int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> n;
        for(int i = 1 ; i <= n ; i++){

        }
    }
}