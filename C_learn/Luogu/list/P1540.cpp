// #include<iostream>
// #include<queue>
// using namespace std;
// int main(){
//     int M , N;
//     queue<int> queue;
//     int sum = 0;
//     int num[1001] = {0};
//     cin >> M >> N;
//     for(int i = 0 ; i < N ;i++){
//         int n;
//         cin >> n;
//         if(num[n] == 0){
//             if(queue.size() == M){
//                 int k = queue.front();
//                 num[k] = 0;
//             }
//             sum++;
//             num[n] = 1;
//             queue.push(n);
//         }
//     }
//     cout << sum;
//     return 0;
// }


#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int sum = 0;
    vector<int> vec;
    int N , M;
    cin >> M >> N;
    for(int i = 0 ; i < N ; i++){
        int n;
        cin >> n;
        if(find(vec.begin(),vec.end(),n) == vec.end()){
            vec.push_back(n);
            sum++;
        }
        if(vec.size() > M) vec.erase(vec.begin());
    }
    cout << sum;
    return 0;
}