// #include<stdio.h>
// int main(){
//     double a,b,c,d;
//     while (scanf("%lf %lf %lf %lf",&a,&b,&c,&d) != EOF)
//     {
//         if(a + c == 0 && b + d == 0) printf("(%.1f%+.1fi) + (%.1f%+.1fi) = 0.0\n",a,b,c,d);
//         else printf("(%.1f%+.1fi) + (%.1f%+.1fi) = %.1f%+.1fi\n",a,b,c,d,a + c,b + d);
//         if(a - c == 0 && b - d == 0) printf("(%.1f%+.1fi) - (%.1f%+.1fi) = 0.0\n",a,b,c,d);
//         else printf("(%.1f%+.1fi) - (%.1f%+.1fi) = %.1f%+.1fi\n",a,b,c,d,a - c,b - d);
//         if(a * c - b * d == 0 && a * d + b * c == 0) printf("(%.1f%+.1fi) * (%.1f%+.1fi) = 0.0\n",a,b,c,d);
//         else printf("(%.1f%+.1fi) * (%.1f%+.1fi) = %.1f%+.1fi\n",a,b,c,d,a * c - b * d,a * d + b * c);
//         if((a*c+b*d)/(c*c+d*d) == 0 && (c*b-a*d)/(c*c+d*d) == 0) printf("(%.1f%+.1fi) / (%.1f%+.1fi) = 0.0\n",a,b,c,d);
//         else printf("(%.1f%+.1fi) / (%.1f%+.1fi) = %.1f%+.1fi\n",a,b,c,d,(a*c+b*d)/(c*c+d*d),(c*b-a*d)/(c*c+d*d));
//     }
// }
#include<stdio.h>
int main(){
    double a,b,c,d;
    while(scanf("%lf%lf%lf%lf",&a,&b,&c,&d)!=EOF){
        if(a+c!=0&&b+d!=0) printf("(%.1lf%+.1lfi) + (%.1lf%+.1lfi) = %.1lf%+.1lfi\n",a,b,c,d,a+c,b+d);
        else if(a+c!=0&&b+d==0) printf("(%.1lf%+.1lfi) + (%.1lf%+.1lfi) = %.1lf\n",a,b,c,d,a+c);
        else if(a+c==0&&b+d!=0) printf("(%.1lf%+.1lfi) + (%.1lf%+.1lfi) = %.1lfi\n",a,b,c,d,b+d);
        else printf("(%.1lf%+.1lfi) + (%.1lf%+.1lfi) = 0.0\n",a,b,c,d);
        if(a-c!=0&&b-d!=0) printf("(%.1lf%+.1lfi) - (%.1lf%+.1lfi) = %.1lf%+.1lfi\n",a,b,c,d,a-c,b-d);
        else if(a-c!=0&&b-d==0) printf("(%.1lf%+.1lfi) - (%.1lf%+.1lfi) = %.1lf\n",a,b,c,d,a-c);
        else if(a-c==0&&b-d!=0) printf("(%.1lf%+.1lfi) - (%.1lf%+.1lfi) = %.1lfi\n",a,b,c,d,b-d);
        else printf("(%.1lf%+.1lfi) - (%.1lf%+.1lfi) = 0.0\n",a,b,c,d);
        if(a*c-b*d!=0&&a*d+b*c!=0) printf("(%.1lf%+.1lfi) * (%.1lf%+.1lfi) = %.1lf%+.1lfi\n",a,b,c,d,a*c-b*d,a*d+b*c);
        else if(a*c-b*d!=0&&a*d+b*c==0) printf("(%.1lf%+.1lfi) * (%.1lf%+.1lfi) = %.1lf\n",a,b,c,d,a*c-b*d);
        else if(a*c-b*d==0&&a*d+b*c!=0) printf("(%.1lf%+.1lfi) * (%.1lf%+.1lfi) = %.1lfi\n",a,b,c,d,a*d+b*c);
        else printf("(%.1lf%+.1lfi) * (%.1lf%+.1lfi) = 0.0\n",a,b,c,d);
        if(a*c+b*d!=0&&b*c-a*d!=0) printf("(%.1lf%+.1lfi) / (%.1lf%+.1lfi) = %.1lf%+.1lfi\n",a,b,c,d,(a*c+b*d)/(c*c+d*d),(b*c-a*d)/(c*c+d*d));
        else if(a*c+b*d==0&&b*c-a*d!=0) printf("(%.1lf%+.1lfi) / (%.1lf%+.1lfi) = %+.1lfi\n",a,b,c,d,(b*c-a*d)/(c*c+d*d));
        else if(a*c+b*d!=0&&b*c-a*d==0) printf("(%.1lf%+.1lfi) / (%.1lf%+.1lfi) = %.1lf\n",a,b,c,d,(a*c+b*d)/(c*c+d*d));
        else printf("(%.1lf%+.1lfi) / (%.1lf%+.1lfi) = 0.0\n",a,b,c,d);
        }
    return 0;
}