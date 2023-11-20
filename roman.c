#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *solution(int);

void main(){
    printf("%s",solution(71));
}


char *solution(int n) {

  int i = 0;
  char* RL;
  RL = malloc(sizeof(char) * 20);
  
  while(n > 0){
    while(n >= 900){
        if(n >= 1000){
            RL[i] = 'M';
            i++;
            n = n - 1000;
        }
        else{
            RL[i] = 'C';
            i++;
            RL[i] = 'M';
            i++;
            n = n - 900;
        }
    }
    while(n >= 400){
        if(n >= 500){
            RL[i] = 'D';
            i++;
            n = n - 500;
        }
        else{
            RL[i] = 'C';
            i++;
            RL[i] = 'D';
            i++;
            n = n - 400;
        }
    }
    while(n >= 90){
        if(n >= 100){
            RL[i] = 'C';
            i++;
            n = n - 100;
        }
        else{
            RL[i] = 'X';
            i++;
            RL[i] = 'C';
            i++;
            n = n - 90;
        }
    }
    while(n >= 40){
        if(n >= 50){
            RL[i] = 'L';
            i++;
            n = n - 50;
        }
        else{
            RL[i] = 'X';
            i++;
            RL[i] = 'L';
            i++;
            n = n - 40;
        }
    }
    while(n >= 9){
        if(n >= 10){
            RL[i] = 'X';
            i++;
            n = n - 10;
        }
        else{
            RL[i] = 'I';
            i++;
            RL[i] = 'X';
            i++;
            n = n - 9;
        }
    }
    while(n >= 4){
        if(n >= 5){
            RL[i] = 'V';
            i++;
            n = n - 5;
        }
        else{
            RL[i] = 'I';
            i++;
            RL[i] = 'V';
            i++;
            n = n - 4;
        }
    }
    while(n > 0){
        RL[i] = 'I';
        i++;
        n--;
    }
    
  }
  return RL;
}



//7 = Vii
//199 = C

/*
while N > 0{
    while N >= 9 {
        if N >= 10{
            RL = RL + "X"
            N = N - 10
        }
        else{
            RL = RL + "IX"
            N = N - 9
        }
    }
    while N >= 4{
        if N >= 5{
            RL = RL + 'V'
            N = N - 5
        }
        else{
            RL = RL + "IV"
            N = N - 4
        }
    }
    While N > 0{
        RL = RL + "I"
        N = N - 1

    }
}

*/