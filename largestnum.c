#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int last_digit(const char *a, const char *b){
    printf("\nb = %s\n", b);
    long long aa, bb;
    aa = atoi(a);
    char *endPoint;
    bb = strtoll(b, &endPoint, 10);
    if(*endPoint != '\0' && *endPoint != '\n')
        return -1;
    aa = aa % 10;
    if((aa == 0 && bb == 0) || bb == 0)
        return 1;
    int prod = 1;
    int i = 1;
    while(1){
        printf("bb = %ld\n", bb);
        if(bb % 2 == 1){ 
            prod = (prod * pow(aa,i));
            prod = prod % 10;
        }
        if(bb == 1)
            break;
        bb = bb / 2;
        i = i * 2;
        
    }
    return prod;
}


void main(){
    printf("%d",1/2);
}









//b = 2037035976334486086268445688409378161051468393665936250636140449354381299763336706183397376
//bb = 9223372036854775807