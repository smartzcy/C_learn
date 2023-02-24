#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    long long m;
    cin >> n >> m;
    int num[100000];
    for(int i = 0 ; i < n;i++){
        cin >> num[i];
    }
    sort(num,num + n);
    int max = 1;
    for(int i = 0 ; i < n;i++){
        for(int j = i + max; j < n;j++){
            if(num[i] * m >= num[j]) max = j - i + 1;
            else break;
        }
    }
    cout << max << endl;
    return 0;
}