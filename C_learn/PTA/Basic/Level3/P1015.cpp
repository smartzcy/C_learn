#include<iostream>
#include<algorithm>
using namespace std;
int N , L , H;
struct Student{
    string id;
    int de;
    int cai;
    int zong;
    int clas;
} student[100000];
bool com(const Student a , const Student b){
    if(a.clas != b.clas) return a.clas < b.clas;
    else if(a.zong != b.zong) return a.zong > b.zong;
    else if(a.de != b.de) return a.de > b.de;
    else return a.id < b.id;
}
int main(){
    cin >> N >> L >> H;
    int cnt = N;
    for(int i = 0 ; i < N;i++){
        cin >> student[i].id >> student[i].de >> student[i].cai;
        student[i].zong = student[i].de + student[i].cai;
        if(student[i].de < L || student[i].cai < L){
            student[i].clas = 5;
            cnt--;
        }else if(student[i].de >= H && student[i].cai >= H)student[i].clas = 1;
        else if(student[i].de >= H && student[i].cai < H) student[i].clas = 2;
        else if(student[i].de < H && student[i].cai < H && student[i].de >= student[i].cai) student[i].clas = 3;
        else student[i].clas = 4;
    }
    sort(student,student + N,com);
    cout << cnt << endl;
    for(int i = 0 ; i < cnt;i++){
        cout << student[i].id << " " << student[i].de << " " << student[i].cai;
        if(i != cnt - 1) cout << endl;
    }
    return 0;
}