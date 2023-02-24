#include <iostream>
#include<cmath>
using namespace std;
const double PI = acos(-1.0);
const double eqs = 1e-6;
double s;
double V(double r){
    return PI * r * r / 3 * sqrt((s / PI / r - r) * (s / PI / r - r) - r * r);
}
int main(){
    cin >> s;
    //pi * r * l + pi * r * r
    //pi * r * r * h / 3
    //h = sqrt(l * l - r * r)
    double l = 0.0 , r = 60.0;
    while(fabs(l - r) > eqs){
        double mid = (l + r) / 2;
        if(V(mid + eqs) > V(mid - eqs)) l = mid;
        else r = mid;
    }
    cout << V(l) << endl;
    cout << sqrt((s / PI / l - l) * (s / PI / l - l) - l * l) << endl;
    cout << l << endl;
}