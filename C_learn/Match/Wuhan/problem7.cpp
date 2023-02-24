// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// int mod = 1e9 + 7;
// struct Tree{
//     int val;
//     int id;
//     Tree* right;
//     Tree* left;
//     Tree(int val , int id) : val(val) ,id(id), right(nullptr) , left(nullptr){}
// };
// vector<vector<int>> vec;
// Tree* insert(Tree* root , int val , int start , int end, int level){
//     if(root == nullptr) return NULL;
//     if(root->id == start){
//         vec.push_back({val , level});
//         if(root->right == NULL) return new Tree(val , end);
//         if(root->left == NULL) return new Tree(val , end);
//     }
//     root->right = insert(root->right, val , start , end , level + 1);
//     root->left = insert(root->left, val , start , end , level + 1);
//     return root;
// }
// int main(){
//     int n;
//     int num[200001];
//     cin >> n;
//     for(int i = 1; i <= n; i++){
//         cin >> num[i];
//     }
//     Tree* root = new Tree(num[1] , 1);
//     vec.push_back({num[1],0});
//     for(int i = 1 ; i < n;i++){
//         int x , y;
//         cin >> x >> y;
//         root = insert(root , num[y] , x , y , 0);
//     }
//     int sum = 0;
//     vector<vector<int>>::iterator it = vec.begin();
//     for(;it != vec.end(); it++){
//         for(vector<vector<int>>::iterator it2 = it + 1; it2 != vec.end();it2++){
//             sum = (sum + max((*it)[0] , (*it2)[0]) * ((*it)[1] + (*it2)[1]) % mod) % mod;
//         }
//     }
//     cout << mod << endl;
// }


#include<iostream>
#include<algorithm>
#include<vector>
const int mod = 1e9 + 7;
using namespace std;
int main(){
    vector<vector<long long>> vec;
    int n;
    cin >> n;
    for(int i = 0 ; i < n;i++){
        int num;
        cin >> num;
        vec.push_back(vector<long long>{num});
    }
    vec[0].push_back(0);
    for(int i = 0 ; i < n - 1 ;i++){
        int x , y;
        cin >> x >> y;
        vec[y - 1].push_back(vec[x - 1][1] + 1);
    }
    long long sum = 0;
    for(vector<vector<long long> >::iterator it = vec.begin(); it != vec.end();it++){
        for(vector<vector<long long>>::iterator it1 = it + 1; it1 != vec.end();it1++){
            sum = (sum + max((*it)[0] , (*it1)[0]) * ((*it)[1] + (*it1)[1]) % mod) % mod;
        }
    }
    cout << sum;
}