// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// int main(){
//     vector<int> vec;
//     int T;
//     cin >> T;
//     while (T--){
//         int N;
//         cin >> N;
//         for(int i = 0; i < N; i++){
//             int num;
//             cin >> num;
//             vec.push_back(num);
//         }
//         cin >> N;
//         for(int i = 0 ; i < N; i++){
//             int num;
//             cin >> num;
//             if(binary_search(vec.begin(),vec.end(),num)){
//                 cout << "Yes" << "\n";
//             }else {
//                 cout << "No" << "\n";
//             }
//         }
//         vec.clear();
//     }
//     return 0;
// }
#include<iostream>
#include<map>
using namespace std;
int main(){
    map<int,int> map;
    int T;
    cin >> T;
    while (T--){
        int N;
        cin >> N;
        for(int i = 0; i < N;i++){
            int num;
            cin >> num;
            map.insert(pair<int,int>(num,1));
        }
        cin >> N;
        for(int i = 0;i < N;i++){
            int num;
            cin >> num;
            if(map.find(num) != map.end()){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
        map.clear();
    }
    return 0;
}