#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    vector<string> vec;
    int n , k;
    cin >> n >> k;
    int sum = 0;
    for(int i = 0 ; i < n;i++){
        int num;
        cin >> num;
        if(i == 0) sum = num;
        else if(num - sum != k){
            string str;
            sum += k;
            if(num > sum) str += "- ";
            else str += "+ ";
            str += to_string(i + 1);
            cout << num << " " << sum << endl;
            str += " " + to_string(abs(num - sum));
            vec.push_back(str);
        }
    }
    cout << vec.size() << endl;
    for(auto i : vec){
        cout << i << endl;
    }
}