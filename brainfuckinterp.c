// void brainfuck(const char *code, const char *input, char *output)
// code - The Brainfuck program to be executed
// input - A stream of input bytes to the Brainfuck program being executed
// output - A writable character buffer large enough to hold the expected output of the
//          Brainfuck program being executed
// Your task: Execute the Brainfuck program with the given input, writing the program output
// to the output buffer provided as a NUL-terminated C-string
#include <stdio.h>
#include <stdlib.h>

int matchingBracket(const char *code, int i){
    int amountOfBrackets = 1;
    if(code[i] == '['){
        while(amountOfBrackets != 0){
            i++;
            if(code[i] == '['){
                amountOfBrackets++;
            }
            else if(code[i] == ']'){
                amountOfBrackets--;
            }
        }
        return i;

    }
    else if(code[i] == ']'){
        while(amountOfBrackets != 0){
            i--;
            if(code[i] == ']'){
                amountOfBrackets++;
            }
            else if(code[i] == '['){
                amountOfBrackets--;
            }
        }
        return i;
    }
    else{
        printf("invalid input into the matchingBracket function it was expecting either [ or ] and got %c\n", code[i]);
    }
    return -1;
}


void brainfuck(const char *code, const char *input, char *output) {
    unsigned char *data;
    data = malloc(sizeof(unsigned char) * 5000);
    for(int i = 0; i < 5000; i++)
        data[i] = '\0';
    int i = 0;                          //I do understand that these 4 indexes could just be pointers
    int currentInputIndex = 0;
    unsigned char *currentDataPtr;
    currentDataPtr = data;
    int currentOutputIndex = 0;
    while(code[i] != '\0'){
        switch(code[i]){
            case '>':
                currentDataPtr = currentDataPtr + sizeof(unsigned char);
                i++;
                break;
            case '<':
                currentDataPtr = currentDataPtr - sizeof(unsigned char);
                i++;
                break;
            case '+':
                (*currentDataPtr)++;
                i++;
                break;
            case '-':
                (*currentDataPtr)--;
                i++;
                break;
            case '.':
                output[currentOutputIndex] = *currentDataPtr;
                currentOutputIndex++;
                i++;
                break;
            case ',':
                *currentDataPtr = input[currentInputIndex];
                currentInputIndex++;
                i++;
                break;
            case '[':
                if(*currentDataPtr != '\0'){                
                    i++;
                }
                else{
                    i = matchingBracket(code, i) + 1;
                }
                break;
            case ']':
                if(*currentDataPtr == '\0'){                        
                    i++;
                }
                else{
                    i = matchingBracket(code, i) + 1;
                }
                break;

        }
    }
    output[currentOutputIndex] = '\0';
    free(data);
}



void main(){
    char output[1025];
    brainfuck("+++++++,[.,]","helloworld",output);
    printf("This is my output %s\n", output);
}










