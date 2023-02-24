#include<iostream>
#include<algorithm>
using namespace std;
struct Student{
    int id;
    string name;
    int you;
}student[100];
bool cmp(Student a , Student b){
    if(a.you == b.you) return a.id < b.id;
    return a.you < b.you;
}
int main(){
    int n;
    cin >> n;
    for(int i = 0 ; i < n;i++){
        string name , sf;
        cin >> name >> sf;
        student[i].id = i;
        student[i].name = name;
        if(sf == "rat") student[i].you = 1;
        if(sf == "woman" || sf == "child") student[i].you = 2;
        if(sf == "man") student[i].you = 3;
        if(sf == "captain") student[i].you = 4;
    }
    sort(student,student + n,cmp);
    for(int i = 0 ; i < n;i++){
        cout << student[i].name << endl;
    }
}