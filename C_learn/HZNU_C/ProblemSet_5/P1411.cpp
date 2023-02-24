#include<iostream>
#include<cmath>
using namespace std;
int x[1000001];
int main(){
	x[0] = 1;
	for (int i = 1; i < 1000001; i++)
		x[i] = (x[(int)(i-sqrt((double)i))] + x[(int)(log((double)i))] + x[(int)(i*sin(i)*sin(i))])%1000000;
	int n;
	while (cin >> n , n >= 0) cout << x[n] << endl;
    return 0;
}