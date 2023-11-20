#include <stdlib.h>
#include <stdio.h>

int **multiplication_table(int);

void main(){
    int **orcatable;
    orcatable = multiplication_table(4);
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            printf("%d\n", *(*(orcatable + sizeof(int*) * i) + sizeof(int*) * j));
        }
    }
}


int **multiplication_table(int n) {
    int **table;
    table = (int**)malloc(sizeof(int**) * n + 1);
    for(int i = 0; i < n; i++){
        *(table + sizeof(int*) * i) = (int*)malloc(sizeof(int*) * n + 1);
        printf("Memaddr: 0x%x\n",*(table + sizeof(int*) * i));
        if(*(table + sizeof(int*) * i) == NULL){
            printf("warning");
        }
    }

    printf("\n\n\n");
    fflush(stdout);
    *(*(table + sizeof(int*) * 1) + sizeof(int) * 0) = 1;
    printf("Memaddr: 0x%x\n", (*(table + sizeof(int*) * 1) + sizeof(int) * 0));


    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            //*(*(table + sizeof(int*) * 1) + sizeof(int) * 0) = 1;                             When this is uncommented it causes a segfault when i = 0 and j = 1.
            printf("Memaddr: 0x%x\n", (*(table + sizeof(int*) * i) + sizeof(int) * j));
            printf("%d %d\n", i, j);
            fflush(stdout);
            *(*(table + (sizeof(int*) * i)) + (sizeof(int) * j)) = (i + 1) * (j + 1);
        }
    }

    return table;

    //  <----  hajime!

}










//*(*(table + sizeof(int*) * 1) + sizeof(int) * 0) = (1 + 1) * (0 + 1); This one causes segfault (I have replaced the i and j with their vaules when it causes a segfault)

//*(*(table + sizeof(int*) * 1) + sizeof(int) * 0) = 1;            This one does not (This is only true when it is not run in the for loop otherwise refer to line 36)




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