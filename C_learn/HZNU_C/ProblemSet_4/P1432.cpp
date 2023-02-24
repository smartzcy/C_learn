#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int x,y,z;
    while (cin >> x >> y >> z,x != 0){
        if(pow(x,2) + pow(y,2) == pow(z,2) || pow(x,2) == pow(y,2) + pow(z,2) || pow(x,2) + pow(z,2) == pow(y,2)) printf("right\n");
        else printf("wrong\n");
    }
    
}