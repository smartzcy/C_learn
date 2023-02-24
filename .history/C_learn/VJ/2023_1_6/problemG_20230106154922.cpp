#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
const double PI = acos(-1.0);
const double eqs = 1e-8;
double s;
double V(double r){
    return sqrt(-2 * s * PI * (r * r - s / 4 / PI) * (r * r - s / 4 / PI) + s * s * s / 8 / PI) / 3;
}
int main(){
    while(cin >> s){
        // pi * r * l + pi * r * r
        // pi * r * r * h / 3
        // h = sqrt(l * l - r * r)
        double l = 0.0, r = sqrt(s / PI);
        while (fabs(l - r) > eqs){
            double mid1 = (l * 2 + r) / 3;
            double mid2 = (l + r * 2) / 3;
            if (V(mid1) < V(mid2))
                l = mid1;
            else
                r = mid2;
        }
        printf("%.2lf\n", V(l));
        printf("%.2lf\n", sqrt((s / PI / l - l) * (s / PI / l - l) - l * l));
        printf("%.2lf\n", l);
    }
}
