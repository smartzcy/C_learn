#include<stdio.h>

struct number
{
    int a;
    int b;
    int c;
    double ave;
};


int main(){

struct number get[500];

int n, i;

scanf("%d", &n);

for( i=0 ; i<n ; i++ ){

scanf("%d%d%d", &get[i].a, &get[i].b, &get[i].c);

get[i].ave = (get[i].a+get[i].b+get[i].c)/3.0;

}

for( i=n-1 ; i>0 ; i--){

printf("%lf ", get[i].ave);

}

printf("%lf\n", get[0].ave);

return 0;

}