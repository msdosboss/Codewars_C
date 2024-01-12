#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



/*TODO Change ii into a dynmically sized array of longs because ii as a single long gets to large to fit in the 8 bytes that it is given so we are working on the fact that a^4 * a^4 = a^8 there by allowing us to seperate the pow() calculations into multiple parts*/

int last_digit(const char *a, const char *b){
    printf("\na = %s\n", a);
    printf("\nb = %s\n", b);
    long long aa;
    aa = atoi(a);
    char *bb;
    bb = malloc(sizeof(char) * strlen(b) + 1);
    for(int i = 0; i < strlen(b); i++){
        bb[i] = '\0';
    }
    strcpy(bb,b);
    int lenbb = strlen(bb);
    if(bb[strlen(bb)] == '\0')
        printf("\nbb[1] is null\n");
    aa = aa % 10;
    if((aa == 0 && bb[1] == '\0' && bb[0] == 0) || (bb[1] == '\0' && bb[0] == 0))
        return 1;
    int prod = 1;
    long ii = 1;
    while(1){
        printf("\nii = %d\n", ii);
        printf("bb = %s\n", bb);
        if((bb[lenbb - 1] - '0') % 2 == 1){
            printf("\nii = %d\n",ii);
            /*for(int i = 0; i < ii; i++){
                prod = prod * aa;
                prod = prod % 10;
            }*/
            prod = (prod * pow(aa,ii));
            prod = prod % 10;
        }
        if(bb[lenbb - 1] == '1' && bb[lenbb - 2] == '\0') 
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
            printf("shortning the string\n");
            lenbbb++;
        }
        printf("this is bb before get shrunk %s\n", bb);
        if(lenbb != 0){ 
            char *bbb;
            bbb = malloc(sizeof(char) * (lenbb - lenbbb) + 1);
            strcpy(bbb,&bb[lenbbb]);
            bb = realloc(bb, sizeof(char) *(lenbb - lenbbb) + 1);
            strcpy(bb,bbb);
            free(bbb);
            lenbb = strlen(bb);
        }
        ii = ii * 2;
        
    }
    free(bb);
    printf("this is prod before return: %d", prod);
    return prod;
}


void main(){
    printf("\n%d\n", sizeof(long));
    //printf("\n%d\n",last_digit("1606938044258990275541962092341162602522202993782792835301376","2037035976334486086268445688409378161051468393665936250636140449354381299763336706183397376"));
}









//b = 2037035976334486086268445688409378161051468393665936250636140449354381299763336706183397376
//bb = 9223372036854775807
//144115188075855872
// 720575