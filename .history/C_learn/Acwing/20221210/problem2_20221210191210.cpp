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
            if(num > sum + k) str += "+ ";
            else str += "- ";
            str += to_string(i + 1);
            str += " " + to_string(abs(num - sum - k));
            vec.push_back(str);
            sum += k;
        }
    }
    cout << vec.size() << endl;
    for(auto i : vec){
        cout << i << endl;
    }
}