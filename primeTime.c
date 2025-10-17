#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

//  assign values to pre-allocated array *primes
//  set *z as the length of this output

int isPrime(int n){
    if (n < 2) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;

    for(int i = 3; i * i <= n; i += 2){
        if(n % i == 0){
        return 0;
        }
    }
    return 1;
}

void prime(unsigned m, size_t *z, unsigned *primes) {
    int idx = 0;
    for(int i = 0; i <= m; i++){
        if(isPrime(i)){
            primes[idx++] = i;
        }
    }
    *z = idx;
}

int main(){
    unsigned m = 1000000000;
    size_t len;
    unsigned *primes = malloc(sizeof(unsigned) * m);
    prime(m, &len, primes);
    for(int i = 0; i < len; i++){
        printf("%d\n", primes[i]);
    }
    return 0;
}
