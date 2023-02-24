#include<stdio.h>
int main(){
    int T;
    scanf("%d",&T);
    int days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    char week[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    while (T--)
    {
        int year , month, day;
        int all_day = 0;
        scanf("%d-%d-%d",&year,&month,&day);
        if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0) days[2] = 29;
        else days[2] = 28;
        for(int i = 0 ; i < month;i++){
            all_day += days[i];
        }
        if(month == 1 || month == 2){
            year -= 1;
            month += 12;
        }
        int WeekDay = (day + 1 + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400) % 7;
        printf("%d %s\n",all_day + day,week[WeekDay]);
    }
    
}