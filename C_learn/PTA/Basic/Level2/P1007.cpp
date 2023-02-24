#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int num[100001];
    for(int i = 2 ; i <= n;i++) num[i] = 1;
    num[1] = 0;
    for(int i = 2 ; i < n;i++)
        if(num[i])
            for(int j = i, k = 2; j * k <= n;k++)
                num[j * k] = 0;
    int count = 0;
    for(int i = 2; i < n;i++)
        if(num[i] == 1 && num[i + 2] == 1)
            count++;
    cout << count << endl;
}