#include<iostream>
#include<set>
using namespace std;
int main(){
    typedef set<int> Set;
    ios::sync_with_stdio(false);
    cin.tie(0);
    Set s;
    int n;
    while (cin >> n){
        for(int i=0; i<n; i++){
            int num;
            cin >> num;
            if(s.find(num) == s.end()){
                s.insert(num);
            }
        }
        cout << s.size() << endl;
        int flag = 0;
        for (Set::const_iterator p = s.cbegin(); p != s.cend(); ++p){
            if(flag == 0){
                cout << *p;
                flag = 1;
            }else{
                cout << ' ' << *p;
            }
        }
        cout << endl;
        s.clear();
    }
    return 0;
}