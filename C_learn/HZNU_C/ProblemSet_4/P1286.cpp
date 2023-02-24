#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int num[1000];
        int n , sum = 0;
        cin >> n;
        for(int i = 0 ; i < n;i++){
            cin >> num[i];
            sum += num[i];
        }
        int number = 0;
        double average = sum / (double)n;
        for(int i = 0 ; i < n;i++){
            if(num[i] > average) number++;
        }
        printf("%.3f%\n",number / (double)n * 100);
    }
}