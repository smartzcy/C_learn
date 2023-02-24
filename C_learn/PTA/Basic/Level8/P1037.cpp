#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    int Galleon , Sickle , Knut;
    int a1 , a2 , a3;
    int flag = 1;
    scanf("%d.%d.%d %d.%d.%d",&Galleon , &Sickle , &Knut, &a1, &a2, &a3);
    if(a1 * 17 * 29 + a2 * 29 + a3 >= Galleon * 17 * 29 + Sickle * 29 + a3){
        a3 -= Knut;
        a2 -= Sickle;
        a1 -= Galleon;
    }else{
        flag = -1;
        a3 = Knut - a3;
        a2 = Sickle - a2;
        a1 = Galleon - a1;
    }
    if(a3 < 0){
        a3 += 29;
        a2--;
    }
    if(a2 < 0){
        a2 += 17;
        a1--;
    }
    printf("%d.%d.%d",a1 * flag,a2,a3);
}