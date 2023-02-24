#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int year;
    while(cin >> year, year != 0){
        double d = log(4);
        for(int i = 1960; i <= year; i+=10){
            d *= 2;
        }
        int i = 1;
        double f = 0;
        while(f < d){
            f += log(i++);
        }
        cout << i - 2 << endl;
    }
    return 0;
}