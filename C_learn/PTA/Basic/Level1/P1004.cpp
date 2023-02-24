#include<iostream>
#include<algorithm>
using namespace std;
struct Student{
    string name;
    string id;
    int score;
};
bool com(const Student x , const Student y){
    return x.score < y.score;
}
int main(){
    int T;
    struct Student student[1000];
    cin >> T;
    for(int i = 0 ;i < T;i++){
        cin >> student[i].name >> student[i].id >> student[i].score;
    }
    sort(student,student + T,com);
    cout << student[T - 1].name << " " << student[T - 1].id << endl;
    cout << student[0].name << " " << student[0].id << endl;
}