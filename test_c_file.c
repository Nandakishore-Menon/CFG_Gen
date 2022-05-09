#include <stdio.h>

int main(void){
    int a=0;
    long d=0;
    while(a<10){
        a++;
        while(d<10)d++;
    }

    if      (a>10)       {
        if(a>20)a++;
        else if(a<13)a;
        else {a;}
    }
    else if(a){a;}
    else a;

    return 0;
}