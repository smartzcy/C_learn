#include<iostream>
using namespace std;
int main(){
    int n , m;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            int num;
            cin >> num;

        }
    }
}
/*
a11 a12 a13 a14;
a21 a22 a23 a24;
a31 a32 a33 a34;
a41 a42 a43 a44;
a21-a11 a22-a12 a23-a13 a24-a14;
a31-a21 a32-a22 a33-a23 a34-a24;
a41-a31 a42-a32 a43-a33 a44-a34;

a31 a32 a33 a34;
a11 a12 a13 a14;
a21 a22 a23 a24;
a41 a42 a43 a44;
a11-a31 a12-a32 a13-a33 a14-a34;
a21-a11 a22-a12 a23-a13 a24-a14;
a41-a21 a42-a22 a43-a23 a44-a24;

a31 a32 a33 a34;
a21 a22 a23 a24;
a11 a12 a13 a14;
a41 a42 a43 a44;
a21-a31 a22-a32 a23-a33 a24-a34;
a11-a21 a12-a22 a13-a23 a14-a24;
a41-a11 a42-a12 a43-a13 a44-a14;

*/