#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



int myPow(int a,unsigned long iii){
    int prod = a;
    printf("prod = %d\n", prod);
    printf("iii: %d\n", iii);
    for(unsigned long i = 0; i < iii; i++){
        prod = (prod * prod) % 10;
        
    }
    return prod;
}


/*TODO Change ii into a dynmically sized array of longs because ii as a single long gets to large to fit in the 8 bytes that it is given so we are working on the fact that a^4 * a^4 = a^8 there by allowing us to seperate the pow() calculations into multiple parts*/

int last_digit(const char *a, const char *b){
    printf("\na = %s\n", a);
    printf("\nb = %s\n", b);
    long long aa;
    aa = a[strlen(a) - 1];
    char *bb;
    bb = malloc(sizeof(char) * strlen(b) + 1);
    for(int i = 0; i < strlen(b); i++){
        bb[i] = '\0';
    }
    strcpy(bb,b);
    int lenbb = strlen(bb);
    aa = aa % 10;
    if((aa == 0 && bb[1] == '\0' && bb[0] == 0) || (bb[1] == '\0' && bb[0] == 0))
        return 1;
    int prod = 1;
    //long ii = 1;
    unsigned long *ii;
    //int iiCnt = 0;
    //ii = malloc(sizeof(long));
    //ii[0] = 1;
    int iii = 0;
    char *bbb;
            bbb = malloc(sizeof(char) * strlen(bb) + 1);
            strcpy(bbb,bb);
    while(!(bb[lenbb - 1] == '1' && bb[lenbb - 2] == '\0')){
        for(int i = strlen(bb) - 1; i >= 0 ; i--){
            if(i != strlen(bb) - 1 && bb[i] % 2 == 1)
            bb[i+1] = bb[i+1] + 5;
            bb[i] = ((bb[i] - '0') / 2) + '0';
        }
        int lenbbb = 0;
        for(int i = 0;; i++){
            if(bb[i] != '0')
                break;
            lenbbb++;
        }
        if(lenbb != 0){ 
            char *bbb;
            bbb = malloc(sizeof(char) * (lenbb - lenbbb) + 1);
            strcpy(bbb,&bb[lenbbb]);
            bb = realloc(bb, sizeof(char) *(lenbb - lenbbb) + 1);
            strcpy(bb,bbb);
            free(bbb);
            lenbb = strlen(bb);
        }
        iii++;
    }
    bb = realloc(bb, sizeof(char) * strlen(bbb) + 1);
    strcpy(bb,bbb);
    lenbb = strlen(bb);
    free(bbb);
    while(1){
        printf("iii= %d\n", iii);
        printf("bb = %s\n", bb);
        if((bb[lenbb - 1] - '0') % 2 == 1){
            prod = prod * myPow(aa, iii);
            prod = prod % 10;
            printf("prod is %d\n", prod);
            }
        
        if((bb[lenbb - 1] == '1' && bb[lenbb - 2] == '\0') ) 
            break;

        for(int i = strlen(bb) - 1; i >= 0 ; i--){
            if(i != strlen(bb) - 1 && bb[i] % 2 == 1)
            bb[i+1] = bb[i+1] + 5;
            bb[i] = ((bb[i] - '0') / 2) + '0';
        }
      
        
        
        int lenbbb = 0;                     //this will be the amount of spaces we are getting rid of
        for(int i = 0;; i++){
            if(bb[i] != '0')
                break;
            lenbbb++;
        }
        if(lenbb != 0){ 
            char *bbb;
            bbb = malloc(sizeof(char) * (lenbb - lenbbb) + 1);
            strcpy(bbb,&bb[lenbbb]);
            bb = realloc(bb, sizeof(char) *(lenbb - lenbbb) + 1);
            strcpy(bb,bbb);
            free(bbb);
            lenbb = strlen(bb);
        }
        iii--;
        
        
    }
    printf("iii\n: %d", iii);
    free(bb);
    printf("this is prod before return: %d", prod);
    return prod;
}


void main(){
    printf("\n%d\n",last_digit("1606938044258990275541962092341162602522202993782792835301376","2037035976334486086268445688409378161051468393665936250636140449354381299763336706183397376"));
}









//b = 2037035976334486086268445688409378161051468393665936250636140449354381299763336706183397376
//bb = 9223372036854775807
//144115188075855872
// 720575


/*
a = 8
b = 5
a[0] = a % 10
a[1] = a * a % 10
a[2] = a[1] * a[1] % 10



        if(ii[iiCnt] * 2 < (pow(2,(sizeof(long) * 8)) / 2)){
                printf("ii[iiCnt] is: %ld\n", ii[iiCnt]);
                ii[iiCnt] = ii[iiCnt] * 2;
                printf("ii[iiCnt] is: %ld\n", ii[iiCnt]);
            }
        else{
            printf("ii is being realloc while iicnt = %d", iiCnt);
            iiCnt++;
            ii = realloc(ii, sizeof(long) * (iiCnt + 1));
            ii[iiCnt] = 1;
        }

*/