#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    int flag = 0;
    int num[1000];
    vector<string> vec;
    vector<string> vec1;
    int n , k;
    cin >> n >> k;
    int sum = 0;
    for(int i = 0 ; i < n;i++){
        cin >> num[i];
        if(i == 0) sum = num[i];
        else sum += k;
        if(num[i] != sum){
            string str = "";
            if(num[i] > sum) str += "- ";
            else str += "+ ";
            str += to_string(i + 1);
            str += " " + to_string(abs(num[i] - sum));
            vec.push_back(str);
        }
    }

    for(int i = n - 1 ; i >= 0 ; i--){
        if(i == n - 1) sum = num[i];
        else sum -= k;
        if(sum <= 0) flag = 1;
        if(num[i] != sum){
            string str = "";
            if(num[i] > sum) str += "- ";
            else str += "+ ";
            str += to_string(i + 1);
            str += " " + to_string(abs(num[i] - sum));
            vec1.push_back(str);
        }
    }
    if(vec.size() < vec1.size() || flag == 1){
        cout << vec.size() << endl;
        for(auto i : vec){
            cout << i << endl;
        }
    }else{
        cout << vec1.size() << endl;
        for(auto i : vec1){
            cout << i << endl;
        }
    }
}