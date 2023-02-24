#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
int main() {
    int year, month, day;
    scanf("%2d-%2d-%d", &day, &month, &year);
    printf("%d-%2d-%02d", year, month, day);
    cout << setw(2) << setfill('0') << month << endl;
    cout << setw(2) << setfill('0') << day << endl;
}