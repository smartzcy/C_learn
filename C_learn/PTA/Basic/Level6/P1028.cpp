#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
    int N;
    scanf("%d",&N);
    string bigName , smallName;
    int max = 0 , min = 0;
    int count = 0;
    while(N--){
        string name;
        int year , month , day;
        int num;
        cin >> name;
        scanf("%d/%d/%d",&year,&month,&day);
        num = year * 10000 + month * 100 + day;
        if(num <= 20140906 && num >= 18140906){
            count++;
            if(min == 0){
                max = num;
                min = num;
                bigName = name;
                smallName = name;
            }
            if(min < num){
                min = num;
                smallName = name;
            }
            if(max > num){
                max = num;
                bigName = name;
            }
        }
    }
    if(count == 0) cout << count << endl;
    else cout << count << " " << bigName << " " << smallName << endl;
    return 0;
}