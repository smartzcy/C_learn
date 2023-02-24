#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n;
    vector<int> vec;
    cin >> n;
    int num1[100000];
    for(int i = 0 ; i < n ; i++){
        cin >> num1[i];
        vec.push_back(num1[i]);
    }
    long long sum = 0;
    int k = 0;
    sort(num1 , num1 + n);
    for(int i = n - 1 ; i >= 0 && !vec.empty() ; i--){
        if(find(vec.begin(), vec.end(),num1[i]) != vec.end()){
            k++;
            sum += num1[i];
            vec.erase(find(vec.begin(), vec.end(),num1[i]));
            vec.erase(vec.begin());
            if(k == n / 2) break;
        }
    }
    
    cout << sum;
}