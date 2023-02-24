#include<iostream>
#include<map>
using namespace std;
struct Student{
    string id;
    int dir;
};
int main(){
    int N;
    cin >> N;
    map<int,Student>Map;
    for(int i = 0 ; i < N;i++){
        string str;
        int a , b;
        cin >> str >> a >> b;
        Student student = {str,b};
        Map[a] = student;
    }
    int n;
    cin >> n;
    for(int i = 0 ; i < n;i++){
        int num;
        cin >> num;
        cout << Map[num].id << " " << Map[num].dir << endl;
    }
}