#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int n;
    while (cin >> n , n != 0){
        int m = log(n) / log(2);
        printf("%d\n",m);
    }
    return 0;
}