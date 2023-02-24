#include "stdio.h"
#define short void
#define int void
#define long void
#define float void
#define double void
#define char void
#define struct void
#define const void
#define unsigned void
#define signed void
#define static void
#define if void
#define else void
#define switch void
#define case void
#define for void
#define do void
#define while void
#define goto void
#define continue void
#define break void
#define default void
#define sizeof void
#define return void
#undef int
#undef while
using namespace std;
int main(){
    int a , b;
    while(~scanf("%d %d",&a,&b)){
        printf("%d\n",a + b);
    }
}