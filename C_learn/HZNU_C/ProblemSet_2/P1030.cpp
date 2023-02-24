#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> vec;
    int T;
    cin >> T;
    while (T--){
        int N;
        cin >> N;
        for(int i = 0 ; i < N;i++){
            int num;
            cin >> num;
            vec.push_back(num);
        }
        cin >> N;
        while (N--){
            char a;
            int n,m;
            cin >> a;
            if(a == 'D'){
                cin >> n;
                vec.erase(vec.begin() + n);
            }else if (a == 'U'){
                cin >> n >> m;
                vec.insert(vec.begin() + n , m);
            }else if (a == 'P'){
                cout << vec[0];
                for (int i = 1; i < vec.size(); i++) {
                    cout << " " << vec[i];
                }
                cout << endl;
            }
        }
        cout << endl;
        vec.clear();
    }
    return 0;
}