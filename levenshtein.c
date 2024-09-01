#include <string.h>
#include <stdlib.h>
#include <stdio.h>

unsigned levenshtein(const char *a, const char *b) {
	int aLength = strlen(a);
	int bLength = strlen(b);

	int **dp = malloc(sizeof(int *) * (bLength + 1));
	for(int i = 0; i <= bLength; i++){
		dp[i] = malloc(sizeof(int) * (aLength + 1));
	}

	for(int i = 0; i <= bLength; i++){
		dp[i][0] = i;
	}
	for(int i = 0; i <= aLength; i++){
		dp[0][i] = i;
	}

	for(int i = 1; i <= bLength; i++){
		for(int j = 1; j <= aLength; j++){
			int minVal = dp[i - 1][j - 1];
			if(dp[i - 1][j] < minVal){
				minVal = dp[i - 1][j];
			}
			if(dp[i][j - 1] < minVal){
				minVal = dp[i][j - 1];
			}
			dp[i][j] = minVal + ((a[j - 1] == b[i - 1]) ? 0 : 1);
		}
	}

	int result = dp[bLength][aLength];

	printf("blen = %d\n", bLength);

	for(int i = 0; i <= bLength; i++){
		for(int j = 0; j <= aLength; j++){
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}

	for(int i = 0; i <= bLength; i++){
		free(dp[i]);
	}
	free(dp);

	return result;
}
