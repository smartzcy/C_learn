#include<iostream>
using namespace std;
struct Student{
    int yu;
    int shu;
    int yin;
    int score;
}students[1000];
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> students[i].yu >> students[i].shu >> students[i].yin;
        students[i].score = students[i].yu + students[i].shu + students[i].yin;
    }
    int sum = 0;
    for(int i = 0 ; i < n; i++){
        for(int j = i + 1 ; j < n; j++){
            if(abs(students[i].yu - students[j].yu) <= 5 && abs(students[i].shu - students[j].shu) <= 5 && abs(students[i].yin - students[j].yin) <= 5 && abs(students[i].score - students[j].score) <= 10){
                sum++;
            }
        }
    }
    cout << sum;
}