#include<stdio.h>
#include<math.h>

int happy(int year, int month, int day){
    int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(month < 1 || month > 12) return -1;
    if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0) days[1] = 29;
    if(day > 0 && day <= days[month-1]){
        return 1;
    }else{
        return -2;
    }
}

int main() {
    char ch;
    int year, month, day;
    while (scanf("%d%c%d%c%d", &year, &ch, &month, &ch, &day) != EOF) {
        printf("%d ", happy(year, month, day));
    }
    return 0;
}