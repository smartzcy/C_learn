#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
int main(){
    int n;
    cin >> n;
    int sum = 0;
    set<int> s;
    for(int i = 0 ; i < n ;i++){
        int num;
        cin >> num;
        sum += min(abs(num - *s.lower_bound(num)) , abs(num - *s.upper_bound(num)));
        cout << sum << endl;
        s.insert(num);
    }
    cout << sum;
}