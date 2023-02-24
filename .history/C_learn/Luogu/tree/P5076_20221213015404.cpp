#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
int main(){
    vector<int> vec;
    set<int> s;
    int q;
    cin >> q;
    for(int i = 0 ; i < q;i++){
        int op , x;
        cin >> op >> x;
        if(op == 5){
            vec.push_back(x);
            s.insert(x);
        }else if(op == 1){
            cout << find(vec.begin() , vec.end() , x) - vec.begin() + 1 << endl;
        }else if(op == 2){
            cout << vec[x - 1] << endl;
        }else if(op == 3){
            if(*s.begin() >= x) cout << "−2147483647" << endl;
            else cout << *(--s.lower_bound(x)) << endl;
        }else if(op == 4){
            if(*s.end() <= x) cout << "2147483647" << endl;
            else cout << *s.upper_bound(x) << endl;
        }
    }
}