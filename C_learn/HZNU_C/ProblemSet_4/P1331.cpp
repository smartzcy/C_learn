#include<iostream>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int a , b;
        cin >> a >> b;
        //x + y = a
        //x - y = b;
        if(a - b < 0 || a + b < 0 || (a - b) % 2 != 0 || (a + b) % 2 != 0){
            printf("impossible\n");
        }else {
            printf("%d %d\n",(a + b) / 2,(a - b) / 2);
        }
    }
    return 0;
}