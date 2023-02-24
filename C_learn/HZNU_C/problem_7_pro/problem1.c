#include<stdio.h>
struct ACM
{
    int id;
    int problem1;
    int problem2;
    int problem3;
    int problem4;
    int problem5;
    int problem6;
    int problem7;
    int problem8;
};

int main(){
    int N;
    scanf("%d", &N);
    struct ACM acm[100];
    for(int i = 0; i < N; i++){
        scanf("%d %d %d %d %d %d %d %d %d", &acm[i].id,&acm[i].problem1,&acm[i].problem2,&acm[i].problem3,&acm[i].problem4,&acm[i].problem5,&acm[i].problem6,&acm[i].problem7,&acm[i].problem8);
    }
    int easy = 0;
    for(int i = 1; i < N; i++){
        if(acm[easy].problem1 < acm[i].problem1){
            easy = i;
        }else if (acm[easy].problem1 == acm[i].problem1){
            if(acm[easy].problem2 < acm[i].problem2){
                easy = i;
            }else if (acm[easy].problem2 == acm[i].problem2){
                if(acm[easy].problem3 < acm[i].problem3){
                    easy = i;
                }else if (acm[easy].problem3 == acm[i].problem3){
                    if(acm[easy].problem4 < acm[i].problem4){
                        easy = i;
                    }else if (acm[easy].problem4 == acm[i].problem4){
                        if(acm[easy].problem5 < acm[i].problem5){
                            easy = i;
                        }else if (acm[easy].problem5 == acm[i].problem5){
                            if(acm[easy].problem6 < acm[i].problem6){
                                easy = i;
                            }else if (acm[easy].problem6 == acm[i].problem6){
                                if(acm[easy].problem7 < acm[i].problem7){
                                    easy = i;
                                }else if (acm[easy].problem7 == acm[i].problem7){
                                    if(acm[easy].problem8 < acm[i].problem8){
                                        easy = i;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%d",acm[easy].id);
}