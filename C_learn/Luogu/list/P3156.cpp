#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n , k;
    vector<int> vec;
    cin >> n >> k;
    for(int i = 1 ; i <= n;i++){
        int num;
        cin >> num;
        vec.push_back(num);
    }
    for(int i = 0 ; i < k;i++){
        int num;
        cin >> num;
        cout << vec[num - 1] << endl;
    }
    return 0;
}