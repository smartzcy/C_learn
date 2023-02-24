#include<iostream>
using namespace std;
int main(){
    int M;
    cin >> M;
    while(M--){
        int n;
        while(cin >> n) {
            int sum = 0;
            for(int i = 0; i < n; i++) {
                int num;
                cin >> num;
                sum += num;
            }
            printf("%d\n", sum - n + 1);
        }        
    }
    return 0;
}