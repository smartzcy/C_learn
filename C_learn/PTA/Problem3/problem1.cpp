#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    int year , month , day;
    scanf("%d/%d/%d",&year,&month,&day);
    int num[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0) num[1] = 29;
    for(int i = 0 ; i < month - 1;i++){
        day += num[i];
    }
    cout << day;
}