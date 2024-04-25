#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int longest_palindrome(const char *str_in) {
    int *letterCount;

    letterCount = malloc(sizeof(int *) * 37);                  //enough for all letters and numbers

    memset(letterCount, 0, 37);

    for(int i = 0; i < strlen(str_in); i++){

        if(isalpha(str_in[i])){
            ++letterCount[(tolower(str_in[i]) - 'a')];
        }
        else if(isdigit(str_in[i])){
            ++letterCount[(str_in[i] - ('0' - 26))];         //the -26 exsists because the first 25 eles are res for nums
        }
    }

    int total = 0;
    int orca = 0;

    for(int i = 0; i < 36; i++){
        if(letterCount[i] % 2 == 0){
            total = total + letterCount[i];
        }
        else{
            total = total + letterCount[i] - 1;
            orca++;
        }
    }
    if(orca)
        total++;
    
    return total;


}


int main(){
    printf("\n%d\n",longest_palindrome("*aprEHWZrGe"));     
    return 0;
}