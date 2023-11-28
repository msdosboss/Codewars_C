/*NOW WORKS AS INTENDED*/










#include <stdlib.h>
#include <stdio.h>

int **multiplication_table(int);

void main(){
    printf("\nsizeof(int): %d\nsizeof(int*): %d\n sizeof(int**) %d\n",sizeof(int),sizeof(int*),sizeof(int**));
    int **orcatable;
    orcatable = multiplication_table(4);
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            printf("\nStart of loop\n");
            printf("Memaddr: 0x%x\n", (orcatable[i] + sizeof(int) * j));
            printf("%d\n", *(orcatable[i] + sizeof(int) * j));
            printf("\n%d %d\n\n", i, j);   
        }
        free(orcatable[i]);
    }
    free(orcatable);
    
}


int **multiplication_table(int n) {
    int **table;
    table = (int**)malloc(sizeof(int*) * n);
    for(int i = 0; i < n; i++){
        table[i] = (int*)malloc(sizeof(table) * (n * n));
        printf("Memaddr: 0x%x\n",table[i]);
        if(table[i] == NULL){
            printf("warning");
        }
    }

    //printf("\n\n\n");
    //fflush(stdout);



    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            //printf("\nStart of loop\n");
            //printf("Memaddr: 0x%x\n", (table[i] + sizeof(int) * j));
            //printf("%d %d\n", i, j);
            //fflush(stdout);
            //printf("\n(i + 1) * (j + 1):%d\n",((i + 1) * (j + 1)));
            *(table[i] + (sizeof(int) * j)) = ((i + 1) * (j + 1));
            //printf("\nThis is the value of *(table[i] + (sizeof(int) * j)): %d\n", *(table[i] + (sizeof(int) * j)));
        }
    }

    /*for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            printf("\nStart of loop\n");
            printf("\nMemaddr: 0x%x\n", (table[i] + (sizeof(int)) * j));
            printf("\n%d\n", *(table[i] + sizeof(int) * j));
            printf("\n%d %d\n", i, j);
        }
    }*/

    
    /*printf("\nMemaddr: 0x%x\n", (table[0]));
    printf("\nMemaddr: 0x%x\n", (table[0] + 4));
    printf("\nMemaddr: 0x%x\n", (table[0] + 8));
    printf("\nMemaddr: 0x%x\n", (table[0] + 12));
    printf("\nMemaddr: 0x%x\n", (table[1]));*/

    return table;

    //  <----  hajime!

}













//The question for this program is 

/*
Your task, is to create N×N multiplication table, of size provided in parameter.
For example, when given size is 3:

1 2 3
2 4 6
3 6 9

For the given example, the return value should be:

[[1,2,3],[2,4,6],[3,6,9]]

Note: in C, you must return an allocated table of allocated rows
*/