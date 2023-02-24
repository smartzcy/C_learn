#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e5;
int n, m;
int main() {
    int year, month, day;
    scanf("%d-%d-%d", &day, &month, &year);
    printf("%d-%d-%d", year, month, day);
}