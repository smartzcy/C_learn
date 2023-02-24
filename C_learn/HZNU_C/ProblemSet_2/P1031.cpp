#include<iostream>
#include<numeric>
#include<vector>
using namespace std;
int main(){
    vector<int> vec;
    int T;
    cin >> T;
    while (T--){
        int N;
        cin >> N;
        for(int i = 0; i < N;i++){
            int num;
            cin >> num;
            vec.push_back(num);
        }
        int a , b , s;
        cin >> a >> b >> s;
        int sum = accumulate(vec.begin() + a , vec.begin() + b + 1, s);
        cout << sum << endl;
        vec.clear();
    }
    return 0;
}