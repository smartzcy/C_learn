#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
int main() {
    int year, month, day;
    scanf("%2d-%2d-%d", &day, &month, &year);
    printf("%d-%2d-%2d", year, month, day);
}