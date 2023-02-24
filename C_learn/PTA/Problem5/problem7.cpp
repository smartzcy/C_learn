#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    int num[] = {1,2,3,4,5,6,7,8,9};
    do{
        for(int i = 0 ; i < n;i++){
            cout << num[i];
        }
        cout << endl;
    }while(next_permutation(num,num + n));
}