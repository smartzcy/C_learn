#include<stdio.h>
#include<math.h>
double AREA(double x1,double y1, double r1, double x2,double y2, double r2)
{
	double d = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
	if (d >= r1+r2)
		return 0;
	if (r1>r2)
	{
		double tmp = r1;
		r1 = r2;
		r2 = tmp;
	}
	if(r2 - r1 >= d)
		return 3.1415*r1*r1;
	double ang1=acos((r1*r1+d*d-r2*r2)/(2*r1*d));
	double ang2=acos((r2*r2+d*d-r1*r1)/(2*r2*d));
	return ang1*r1*r1 + ang2*r2*r2 - r1*d*sin(ang1);
}

int main(){
    double x1,y1,x2,y2;
    double r1,r2;
    while (scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2),!(x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0))
    {
        scanf("%lf %lf",&r1,&r2);
        printf("%.2f\n",AREA(x1,y1,r1,x2,y2,r2));
    }
    printf("Over!");
}