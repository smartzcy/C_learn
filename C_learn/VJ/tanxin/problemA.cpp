#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
struct thing{
    double val;
    int num;
    int sum;
    friend bool operator < (const thing& a, const thing& b){
        return a.val < b.val;
    }
}things[200050];
int main(){
    int M , N;
    while(cin >> M >> N , M != -1 && N != -1){
        for(int i = 0 ; i < N ;i++){
            cin >> things[i].sum >> things[i].num;
            things[i].val = (things[i].sum * 1.0) / things[i].num;
        }
        sort(things, things + N);
        double ans = 0.0;
        for(int i = N - 1 ; i >= 0; i--){
            if(M > things[i].num){
                ans += things[i].sum;
                M -= things[i].num;
            }else{
                ans += things[i].val * M;
                break;
            }
        }
        printf("%.3f\n", ans);
    }
}