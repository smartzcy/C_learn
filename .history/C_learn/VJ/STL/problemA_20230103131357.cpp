#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
struct Student{
    string name;
    int sum;
};
bool cmp(const Student& a, const Student& b){
    return a.sum < b.sum;
}
int main(){
    int N , M , G;
    while(cin >> N , N != 0){
        Student student[1001];
        int sum[11];
        cin >> M >> G;
        for(int i = 1 ; i <= M;i++){
            cin >> sum[i];
        }
        for(int i = 1 ; i <= N;i++){
            cin >> student[i].name;
            int k;
            cin >> k;
            for(int j = 0 ; j < k;j++){
                int num;
                cin >> num;
                student[i].sum += sum[num];
            }
        }
        sort(student + 1 , student + N + 1 , cmp);
        vector<string> vec;
        for(int i = N ; i >= 1;i++){
            cout << "1" << endl;
            if(student[i].sum >= G) vec.push_back(student[i].name + " " + to_string(student[i].sum));
        }
        cout << vec.size() << endl;
        for(auto i : vec) cout << i << endl;
    }
    return 0;
}