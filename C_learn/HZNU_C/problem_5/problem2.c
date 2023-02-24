#include<stdio.h>
int main(){
    int year;
    char *str[] = {"Êó", "Å£", "»¢", "ÍÃ", "Áú", "Éß", "Âí", "Ñò", "ºï", "¼¦", "¹·", "Öí"};
    while(scanf("%d",&year) != EOF) {
        if(year >= 1900){
            year = year - 1900;
            year = year % 12;
        }else if(year > 0 && year < 1900){
            year = (year - 1900) * -1;
            year = year % 12;
            year = 12 - year;
        }else{
            year = (year - 1900) * -1;
            year = year % 12;
            year = 12 - year;
            year++;
        }
        printf("%s\n",str[year]);
    }
}