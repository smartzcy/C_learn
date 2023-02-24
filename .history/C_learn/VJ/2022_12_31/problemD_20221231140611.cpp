#include<iostream>
#include<algorithm>
using namespace std;
pair<int , int> num[200001];
int b[200001];
void fun(int i , int j){
    if(i > j) return;
    int m = (i + j) / 2;
    num[m].first = i - j;
    num[m].second = m;
    fun(i , m - 1);
    fun(m + 1 , j);
}
int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        fun(1 , n);
        sort(num + 1 , num + 1 + n);
        for(int i = 1 ; i <= n ; i++) b[num[i].second] = i;
        for(int i = 1 ; i <= n ; i++) cout << b[i] << " ";
        cout << endl;
    }
    return 0;
}