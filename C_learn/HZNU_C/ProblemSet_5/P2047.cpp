#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int li,mj,zl,xy,lucky;
        cin >> li >> mj >> zl >> xy >> lucky;
        int n;
        cin >> n;
        double max = 0;
        while(n--){
            double shang;
            int li1,mj1,zl1,xy1,lucky1;
            double li2,mj2,zl2,xy2,lucky2;
            cin >> shang >> li1 >> mj1 >> zl1 >> xy1 >> lucky1 >> li2 >> mj2 >> zl2 >> xy2 >> lucky2;
            int k = 1;
            if(li2 > 0){
                shang += li*li2;
                if(li < li1) k = 2;
            }
            if(mj2 > 0){
                shang += mj*mj2;
                if(mj < mj1) k = 2;
            }
            if(zl2 > 0){
                shang += zl*zl2;
                if(zl < zl1) k = 2;
            }
            if(xy2 > 0){
                shang += xy*xy2;
                if(xy < xy1) k = 2;
            }
            if(lucky2 > 0){
                shang += lucky*lucky2;
                if(lucky < lucky1) k = 2;
            }
            shang /= k;
            if(max < shang) max = shang;
        }
        printf("%.3f\n",max);
    }
}