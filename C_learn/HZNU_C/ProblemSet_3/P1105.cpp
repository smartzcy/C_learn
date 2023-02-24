#include<stdio.h>
#include<math.h>
using namespace std;
int isPrime(int n){
    int i;
    for ( i = 2; i <= sqrt(n); i++ ){
        if(n % i == 0) return 0;
    }
    return 1;

}
int main(){
    int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    for(int i = 1988 ; i <= 1989; i++){
        for(int j = 0 ; j < 12; j++){
            for(int k = 1 ; k <= days[j] ; k++){
                if(isPrime(i * 10000 + (j + 1) * 100 + k)) printf("%d\n",i * 10000 + (j + 1) * 100 + k);
            }
        }
    }
    return 0;
}