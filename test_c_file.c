#include <stdio.h>

long long main(void){
    int a=0;
    long d=0;
    while(a/*dwq*/</*qsx*/10)/* wd*/{
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
void func1(ac,cas) {
    int x = 0 ;
    int y = 2 ;
    if ( x < 5 ) {
        x = y ;
        y += 1 ;
    }
    x++;
}

void func2() {
    int x = 0 ;
    int y = 2 ;
    for (int i = 0;/*dwsh*/ i < 10; i++)
    /**/
        if (x < 5) {
            x = y ;
            y += 1 ;
        }
        else
            x = 5 ;
    x++;
}

void func3(){
    int x = 0, y=0 ;
    if (x<1) 
        if (x<3) {
            if (x<7)
                if (x<10)
                    while (x<10) {
                        x++;
                    }
            y++;
        }
    x = y;
}

void func4(  )  
{
    int x = 0, y=0 ;
    if (x<1) 
        if (x<3) {
            if (x<7)
                if (x<10)
                    while (x<10) {
                        x++;
                    }
                else
                    x--;
            else
                y--;
            y++;
        }
    x = y;
}

void func5() {
    int x=0;
    switch(x) 
    {
        case 0:
            x++;
        case 1:
        case 2:
            x++;
            x--;
        default:
            break;
    }
}

void func6() {
    int x=0;
    switch(x) {
        case 1:
            x+=1;
        case 2:
            x+= 2;
            break;
        case 3:
            x+=3;
        default:
            x+=x;
    }
    x++;
}

void func7() {
    int x=0;
    for(int i = 0 ; i < 10; i++){
        switch(x) {
            case 1:
            case 2:
            case 3:
                x+=3;
                break;
            default:
        }
    }
}