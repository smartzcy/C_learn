#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    int num[100001];
    cin >> n;
    for(int i = 0 ; i < n;i++){
        cin >> num[i];
    }
    sort(num,num + n);
    for(int i = 0 ; i < n;i++){
        if(i == 0) cout << num[i];
        else cout << " " << num[i];
    }
}