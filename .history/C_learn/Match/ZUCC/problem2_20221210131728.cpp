#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    int num[5] = {0};
    int flag = 0 ;
    int H1 , H2 , m;
    cin >> H1 >> H2 >> m;
    for(int i = 0 ; i < m ; i++){
        int mm , ss , type;
        scanf("%d:%d %d", &mm, &ss, &type);
        if(type == 3 && flag){
            int x;
            cin >> x;
            if(num[x - 1] - mm * 60 - ss > 30){
                num[x - 1] = mm * 60 + ss;
                H1 += (int)((125 + 0.06 * H1) * 0.1);
            }
        }else if(type == 1){
            H1 += 800;
            flag = 1;
        }else if(type == 2){
            H1 += H2;
        }
    }
    cout << H1;
}