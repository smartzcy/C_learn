#include<stdio.h>
using namespace std;
int main(){
    char week[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    int year , month, day;
    while(~scanf("%d %d %d",&year,&month,&day)){
        if(month == 1 || month == 2){
            year -= 1;
            month += 12;
        }
        int WeekDay = (day + 1 + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400) % 7;
        printf("%s\n",week[WeekDay]);
    }
    return 0;
}