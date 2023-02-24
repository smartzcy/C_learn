#include <iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
const double PI = acos(-1.0);
const double eqs = 1e-6;
double s;
double V(double r){
    double l = (s - r * r) / r;
    double h = sqrt(l * l - r * r);
    return PI * r * r * h / 3.0;
}
int main(){
    cin >> s;
    //pi * r * l + pi * r * r
    //pi * r * r * h / 3
    //h = sqrt(l * l - r * r)
    double l = 0.0 , r = sqrt(s);
    while(fabs(l - r) > eqs){
        double mid = (l + r) / 2;
        if(V(mid + eqs) > V(mid - eqs)) l = mid;
        else r = mid;
    }
    printf("%.2lf\n" , V(l));
    printf("%.2lf\n" , sqrt((s / PI / l - l) * (s / PI / l - l) - l * l));
    printf("%.2lf\n" , l);
}