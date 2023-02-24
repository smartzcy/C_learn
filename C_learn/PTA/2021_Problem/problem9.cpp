    #include<iostream>
    #include<math.h>
    #include<stdio.h>
    using namespace std;
    int main(){
        int n;
        double a , p , q;
        cin >> n >> a >> p >> q;
        for(int i = 0 ; i < n;i++){
            a = a * p / sqrt(p * p + q * q);
        }
        printf("%.6f",a);
    }