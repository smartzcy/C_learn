#include<stdio.h>
int main(){
    int year, mouth, day;
    scanf("%d",&year);
    scanf("%d",&mouth);
    scanf("%d",&day);
    if(day == 31){
        if(mouth == 12){
            year++;
            mouth = 1;
            day = 1;
        }else{
            mouth++;
            day = 1;
        }
    }else if(mouth == 4 || mouth == 6 || mouth == 9 || mouth == 11 && day == 30){
        mouth++;
        day = 1;
    }else if(mouth == 2){
        if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0){
            if(day == 29){
                day = 1;
                mouth++;
            }else{
                day++;
            }
        }else{
            if(day == 28){
                day = 1;
                mouth++;
            }else{
                day++;
            }
        }
    }else{
        day++;
    }
    printf("%d %d %d",year,mouth, day);
}