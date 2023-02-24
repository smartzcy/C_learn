#include<iostream>
using namespace std;
struct Student{
    string id;
    string name;
    int score;
};
int main(){
    int T;
    struct Student student[11];
    cin >> T;
    int max = 0;
    for(int i = 0 ; i < T;i++){
        int a , b , c;
        cin >> student[i].id >> student[i].name >> a >> b >> c;
        student[i].score = a + b + c;
        if(student[i].score > student[max].score) max = i;
    }
    cout << student[max].name << " " << student[max].id << " " << student[max].score;
}