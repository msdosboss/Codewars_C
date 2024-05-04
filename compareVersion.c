#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *removeLeadingZeros(char *version){
	int len = strlen(version);
	char *newversion = malloc(sizeof(char) * len + 1);
	int i = 0;
	int j = 0;
	if(len == 1){
		newversion[0] = version[0];
		newversion[1] = '\0';
		return newversion;
	}
	while(version[i] == '0'){
		i++;
	}
	if(version[i] != '\0'){
		newversion[j++] = version[i++];
	}
	while(version[i] != '\0'){
		if(newversion[j - 1] == '.' && ((version[i] == '0' && version[i + 1] != '.') || version[i] == '.')){
			i++;
			continue;
		}
		newversion[j++] = version[i];
		i++;
	}
	if(j > 0){	
		while(newversion[j - 1] == '.'){
			j--;
		}
	}
	newversion[j] = '\0';
	return newversion;
}

int *stringToArrayOfInts(char *version, int *length){
	int dotCount = 1;
	if(strlen(version) == 1){
		int *result = malloc(sizeof(int));
		*result = atoi(version);
		*length = 0;
		return result;
	} 
	for(int i = 0; version[i] != '\0'; i++){
		if(version[i] == '.')
			dotCount++;
	}
	int *intArray = malloc(sizeof(int) * dotCount);
	int j = 0;
	char lastChar = '.';
	for(int i = 0; version[i] != '\0'; i++){
		if(lastChar == '.'){
			intArray[j++] = atoi(&(version[i]));
		}
		lastChar = version[i];
	}
	j--;
	while(intArray[j] == 0){
		j--;
	}
	*length = j;
	return intArray;
}

int compareVersion(char *version1, char *version2){
	version1 = removeLeadingZeros(version1);
	version2 = removeLeadingZeros(version2);
	int i = 0;
	int version1Length = 0;
	int version2Length = 0;
	int *intVersion1 = stringToArrayOfInts(version1, &version1Length);
	int *intVersion2 = stringToArrayOfInts(version2, &version2Length);
	
	int j = 0;	
	for(int i = 0; i <= version1Length && i <= version2Length; i++){
		if(intVersion1[i] > intVersion2[i]){
			return 1;
		}
		if(intVersion2[i] > intVersion1[i]){
			return -1;
		}
		j = i + 1;
		
	}

	if(version1Length > version2Length){
		return 1;
	}
	
	if(version2Length > version1Length){
		return -1;
	}

	return 0;

}

int main(){
	printf("%d\n", compareVersion("99", "200"));
}

//1..1.
//1.1.1.1.1
//1.1.0.2.1
//1.1.1.1.1
//1.1.2.1
