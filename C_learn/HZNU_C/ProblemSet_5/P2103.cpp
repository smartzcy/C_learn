#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        double sum = 0;
        while(n--){
            double m;
            char str[2];
            scanf("%lf%s",&m,str);
            if(str[0] == 'm' && str[1] != 'm'){
                sum += m * 1000;
            }else if(str[0] == 'k'){
                sum += m * 1000 *1000;
            }else if(str[0] == 'd'){
                sum += m * 100;
            }else if(str[0] == 'c'){
                sum += m * 10;
            }else if(str[0] == 'm' && str[1] == 'm'){
                sum += m;
            }
        }
        printf("%.3fm\n",sum / 1000);
    }
}