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
int amountPrimeFactors(int n){
    int primenumbers[50] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229};
    int numberOfPrimes = 0;
    while(isPrime(n) == 0){
        int i = 0;
        for(; n % primenumbers[i] != 0; i++);
        n = n / primenumbers[i];
        numberOfPrimes++; 
    }
    return numberOfPrimes;
}

// function to write
int consecKprimes(int k, struct list* l) {
    printf("this is k: %d\n", k);
    
    struct node *orcanode;
    int matches = 0;
    orcanode = l->head;
    for(size_t i = 0; i < l->sz; i = i + 2){
        int a, b;
        a = (*orcanode).data;
        orcanode = (*orcanode).next;
        b = (*orcanode).data;
        orcanode = (*orcanode).next;
        printf("a is: %d b is: %d\n", a, b);
        a = amountPrimeFactors(a);
        b = amountPrimeFactors(b);
        printf("a is: %d after b is: %d after\n", a, b);
        if(a == k && b == k){
            printf("orca\n");
            matches++;
        }
    }
    return matches;
}


void main(){
    printf("hellowolrd");
}