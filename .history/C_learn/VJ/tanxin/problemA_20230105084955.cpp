#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
struct thing{
    double val;
    int num;
    friend bool operator < (const thing& a, const thing& b){
        return a.val < b.val;
    }
}things[1000];
int main(){
    int M , N;
    while(cin >> M >> N , M && N){
        for(int i = 0 ; i < N ;i++){
            int num;
            cin >> num >> things[i].num;
            things[i].val = (double)num / things[i].num;
        }
        sort(things, things + N);
        double ans = 0.0;
        for(int i = N - 1 ; i >= 0 && M ; i--){
            if(M >= things[i].num){
                ans += things[i].val * things[i].num;
                M -= things[i].num;
            }else{
                ans += things[i].val * M;
                M = 0;
            }
        }
        printf("%.3f\n", ans);
    }
}