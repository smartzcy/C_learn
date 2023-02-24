#include<iostream>
#include<algorithm>
bool cmp(int i , int j){
    return i > j;
}
using namespace std;
int main(){
    int n , k;
    int num[10];
    cin >> n >> k;
    for(int i = 0 ; i < n;i++){
        cin >> num[i];
    }
    sort(num,num + n,cmp);
    do{
        k--;
        if(k == 0){
            for(int i = 0 ; i < n;i++){
                cout << num[i];
            }
            cout << endl;
            break;
        }
    }while(prev_permutation(num,num + n));
}