#include<iostream>
using namespace std;
int k = 0 , n ,it[100];
void way(int a , int b , int c){
    if(a != 0){
        for(int i = b ; i <= a;i++){
            it[c] = i;
            way(a - i,i,c + 1);
        }
    }else{
        k++;
        printf("%d=%d",n,it[0]);
        for(int j = 1; j < c;j++) printf("+%d",it[j]);
        if(k % 4 == 0) printf("\n");
        else if(k % 4 != 0 && it[0] != n) printf(";");
    }
}
int main(){
    cin >> n;
    way(n, 1, 0);
    return 0;
}