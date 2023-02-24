#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
struct yue{
    double num;
    double money;
    double dan;
}yb[1010];
bool cmp(yue a ,yue b){
    return a.dan > b.dan;
}
int main(){
    int n , m;
    cin >> n >> m;
    for(int i = 0 ; i < n;i++){
        cin >> yb[i].num;
    }
    for(int i = 0 ; i < n;i++){
        cin >> yb[i].money;
        yb[i].dan = yb[i].money / yb[i].num;
    }
    sort(yb,yb + n,cmp);
    double count = 0;
    double nm = 0.0;
    for(int i = 0 ; i < n;i++){
        if(count + yb[i].num >= m){
            nm += (m - count) * yb[i].dan;
            break;
        }else{
            nm += yb[i].money;
            count += yb[i].num;
        }
    }
    printf("%.2f",nm);
}