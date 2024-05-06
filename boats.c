//https://leetcode.com/problems/boats-to-save-people/description/

#include <stdio.h>
#include <stdlib.h>

int cmpFunc(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}

int fasterNumRescueBoats(int *people, int peopleSize, int limit){
	qsort(people, peopleSize, sizeof(int), cmpFunc);
	int j = peopleSize - 1;
	int i = 0;
	int boatCount = 0;
	while(i <= j){
		if(people[i] + people[j] <= limit){
			i++;
		}
		j--;
		boatCount++;
	}
	return boatCount;
}


int numRescueBoats(int *people, int peopleSize, int limit){
	int indexOfPair = -1;
	int boatCount = 0;
	for(int i = 0; i < peopleSize; i++){
		if(people[i] == -1){
			continue;
		}
		for(int j = i + 1; j < peopleSize; j++){
			if(people[i] + people[j] <= limit && people[j] != -1){
				if(indexOfPair != -1){
					indexOfPair = people[indexOfPair] > people[j] ? indexOfPair : j;
				}
				else{
					indexOfPair = j;
				}
			}
		}
		boatCount++;
		if(indexOfPair != -1){
			people[indexOfPair] = -1;
			indexOfPair = -1;
		}

	}
	return boatCount;
}

int main(){
	int list[] = {3,5,3,4}; 
	printf("%d\n", fasterNumRescueBoats(list, 4, 5));
	return 0;
}
