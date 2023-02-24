#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    int num[200000];
    for(int i = 0 ; i < n;i++)
        cin >> num[i];
    sort(num,num + n);
    for(int i = 0 ; i < n; i++){
        if(i == 0) cout << num[i];
        else cout << " " << num[i];
    }
    cout << endl;
    int m;
    cin >> m;
    while(m--){
        int num1;
        cin >> num1;
        int i = 0;
        int j = n - 1;
        while(i <= j){
            int mid = (i + j) / 2;
            if(num[mid] > num1){
                j = mid - 1;
            }else{
                i = mid + 1;
            }
        }
        cout << i << endl;
    }
    return 0;
}