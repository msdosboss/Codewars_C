#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// In the preloaded section are some functions that can help.
// They can be used as a small library.
// There is no file to include, only the templates below.

struct node {
    int data;
    struct node *next;
};
struct list {
    size_t sz;
    struct node *head;
};

struct list* createList();

// push data at the head of the list
void insertFirst(struct list* l, int data);

struct list* reverse(struct list* l);

void listFree(struct list* l);

int isPrime(int n){
    if(n <= 1)
        return 0;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0)
            return 0;
    }
    return 1;
}

int amountOfPrimes(struct list* l){
    int largestNumber = 0;
    struct node * orcanode = l->head;
    for(size_t i = 0; i < l->sz; i++){
        if(orcanode->data > largestNumber){
            largestNumber = orcanode->data;
        }
        orcanode = orcanode->next;
    }
    int amountOfPrimeNumbers = 0;
    for(int i = 0; i * 2 < largestNumber; i++){
        if(isPrime(i))
            amountOfPrimeNumbers++;
    }
    return amountOfPrimeNumbers;
}

int * primenumberpointer(struct list* l){
    int largestNumber = 0;
    struct node * orcanode = l->head;
    for(size_t i = 0; i < l->sz; i++){
        if(orcanode->data > largestNumber){
            largestNumber = orcanode->data;
        }
        orcanode = orcanode->next;
    }
    int amountOfPrimeNumbers = amountOfPrimes(l);
    int *primeNumbers = malloc(sizeof(int) * (amountOfPrimeNumbers + 1));
    amountOfPrimeNumbers = 0;
    for(int i = 0; i * 2 < largestNumber; i++){
        if(isPrime(i)){
            primeNumbers[amountOfPrimeNumbers] = i;
            amountOfPrimeNumbers++;
        }
    }
    primeNumbers[amountOfPrimeNumbers] = -1;
    return primeNumbers;
}

int amountPrimeFactors(int n, int *primeNums){
    int numberOfPrimes = 1;
    while(isPrime(n) == 0){
        int i = 0;
        for(; n % primeNums[i] != 0; i++);
        n = n / primeNums[i];
        numberOfPrimes++; 
    }
    return numberOfPrimes;
}

// function to write
int consecKprimes(int k, struct list* l) {
    int *primeNums = malloc(sizeof(int) * (amountOfPrimes(l) + 1));
    primeNums = primenumberpointer(l);
    struct node *orcanode;
    int matches = 0;
    orcanode = l->head;
    for(size_t i = 1; i < l->sz; i++){
        int a, b;
        a = (*orcanode).data;
        orcanode = (*orcanode).next;
        b = (*orcanode).data;
        a = amountPrimeFactors(a, primeNums);
        b = amountPrimeFactors(b, primeNums);
        if(a == k && b == k){
            matches++;
        }
    }
    free(primeNums);
    return matches;
}


void main(){
    printf("hellowolrd");
}