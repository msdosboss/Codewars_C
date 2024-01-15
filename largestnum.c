#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int myPow(int a,unsigned long iii){
    long prod = a;
    for(unsigned long i = 0; i < iii; i++){
        prod = (prod * prod) % 10;
        
    }
    return prod;
}

int last_digit(const char *a, const char *b){
    int aa;
    aa = (a[strlen(a) - 1]) - '0';
    char *bb;
    bb = malloc(sizeof(char) * strlen(b) + 1);
    for(int i = 0; i < strlen(b); i++){
        bb[i] = '\0';
    }
    strcpy(bb,b);
    int lenbb = strlen(bb);
    aa = aa % 10;
   if(strlen(bb) == 1 && bb[0] == '0')
        return 1;
    int prod = 1;
    int iii = 0;
    while(1){
        if((bb[lenbb - 1] - '0') % 2 == 1){
            prod = prod * myPow(aa, iii);
            prod = prod % 10;
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
        if(lenbbb != 0){ 
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
    free(bb);
    return prod;
}


void main(){
    printf("\n%d\n", last_digit("4","1"));
    //printf("\n%d\n",last_digit("1606938044258990275541962092341162602522202993782792835301376","2037035976334486086268445688409378161051468393665936250636140449354381299763336706183397376"));
}
