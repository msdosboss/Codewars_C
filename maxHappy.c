//https://leetcode.com/problems/maximize-happiness-of-selected-children/description/?envType=daily-question&envId=2024-05-09
#include <stdio.h>
#include <stdlib.h>

int cmpFunc(const void *a, const void *b){
	return (*(int*)b - *(int*)a);
}


long long maximumHappinessSum(int *happiness, int happinessSize, int k){
	long long output = 0;
	qsort(happiness, happinessSize, sizeof(int), cmpFunc);
	for(int i = 0; i < k; i++){
		if(happiness[i] - i <= 0){
			continue;
		}
		output += happiness[i] - i;
	}
	return output;
}
