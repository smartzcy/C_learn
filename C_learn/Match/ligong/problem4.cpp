#include<stdio.h>
#include<math.h>
using namespace std;
#define PRECISION 0.0002
double sqrt1(double n) {
	double min, max, mid; //min代表下边界，max代表上边界，mid为中间值也作为近似值
	min = 0;
	max = n>1?n:1;
	mid = n / 2;
	while (mid*mid>n + PRECISION || mid*mid<n - PRECISION)
	{
		mid = (max + min) / 2;
		if (mid*mid < n + PRECISION) {
			min = mid; //根值偏小，升高下边界
		};
		if (mid*mid > n - PRECISION) {
			max = mid;//根值偏大，降低上边界
		}
	}
	return mid;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
            double x , h , a;
            scanf("%lf %lf %lf",&x , &h , &a);
            double a1 = sqrt1(2 * h * 10.0);
            double a2 = sqrt(2 * a * x);
            printf("%.18f %.18f\n",a1,a2);
    }
}

