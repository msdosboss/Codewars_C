#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct TreeNode{
	int val; 
	struct TreeNode *left;
	struct TreeNode *right;
	
};

void isTargetSum(struct TreeNode *current, bool *isSum, int targetSum, int *n){
	*n += current->val;
	if(current->left == NULL && current->right == NULL){
		if(targetSum == *n){
			*isSum = true;
			return;
		}
	}	

	if(current->left != NULL){
		isTargetSum(current->left, isSum, targetSum, n);
	}
	if(current->right != NULL){
		isTargetSum(current->right, isSum, targetSum, n);
	}
	*n -= current->val;
}

bool hasPathSum(struct TreeNode *root, int targetSum){
	if(root == NULL){
		return false;
	}
	bool isSum = false;
	int n = 0;
	isTargetSum(root, &isSum, targetSum, &n);
	return isSum;
}

void mirror(struct TreeNode *currentLeft, struct TreeNode *currentRight, bool *isSym){
	
	if(currentLeft->val != currentRight->val){
		*isSym = false;
		return;
	}	

	if((currentLeft->left != NULL && currentRight->right == NULL) || (currentLeft->left == NULL && currentRight->right != NULL) || (currentLeft->right != NULL && currentRight->left == NULL) || (currentLeft->right == NULL && currentRight->left != NULL)){
		*isSym = false;
		return;
	}

	if(currentLeft->left != NULL && currentRight->right != NULL){
		mirror(currentLeft->left, currentRight->right, isSym);
	}
	if(currentLeft->right != NULL && currentRight->left != NULL){
		mirror(currentLeft->right, currentRight->left, isSym);
	}
}

bool isSymmetric(struct TreeNode *root){
	if(root == NULL){
		return false;
	}
	if(root->right == NULL && root->left == NULL){
		return true;
	}
	if(root == NULL || root->right == NULL || root->left == NULL){
		return false;
	}
	bool *isSym = malloc(sizeof(bool));
	*isSym = true;
	mirror(root->left, root->right, isSym);
	return *isSym;
}


void size(struct TreeNode *root, int *nodeCount){
	if(root == NULL){
		return;
	}
	
	if(root->left != NULL){
		size(root->left, nodeCount);
	}
	if(root->right != NULL){
		size(root->right, nodeCount);		
	}
	++(*nodeCount);

}

void layerCounter(struct TreeNode *root, int *layerCount, int n){
	if(root == NULL){
		return;
	}
	
	
	*layerCount = (*layerCount < n + 1) ? n + 1: *layerCount;
	
	if(root->left != NULL){
		layerCounter(root->left, layerCount, n + 1);
	}
	if(root->right != NULL){
		layerCounter(root->right, layerCount, n + 1);		
	}

}

void nodePerLayerer(struct TreeNode *root, int *nodePerLayer, int n){
	if(root == NULL){
		return;
	}
	nodePerLayer[n]++;
	if(root->left != NULL){
		nodePerLayerer(root->left, nodePerLayer, n + 1);
	}
	if(root->right != NULL){
		nodePerLayerer(root->right, nodePerLayer, n + 1);		
	}

}

int maxDepth(struct TreeNode *root){
	int max = 0;
	layerCounter(root, &max, 0);
	return max;
}

void levelHelper(struct TreeNode *current, int **results, int *index, int n){
	if(current == NULL){
		return;
	}
	

	results[n][(index[n])++] = current->val;
		
	if(current->left != NULL){
		levelHelper(current->left, results, index, n + 1);
	}
	if(current->right != NULL){
		levelHelper(current->right, results, index, n + 1);	
	}
}

int **levelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSize){
	if(root == NULL){
		printf("root was NULL\n");
		*returnColumnSize = NULL;
		*returnSize = 0;
		return NULL;
	}
	*returnSize = 0;	
	layerCounter(root, returnSize, 0);
	int *nodesPerLayer = malloc(sizeof(int) * *returnSize);
	
	int *index = malloc(sizeof(int) * *returnSize);	
	
	for(int i = 0; i < *returnSize; i++){
		nodesPerLayer[i] = 0;
		index[i] = 0;
	}

	
	nodePerLayerer(root, nodesPerLayer, 0);
	
	int **results = malloc(sizeof(int *) * *returnSize);
	*returnColumnSize = malloc(sizeof(int) * *returnSize);

	for(int i = 0; i < *returnSize; i++){
		results[i] = malloc(sizeof(int) * nodesPerLayer[i]);
		returnColumnSize[0][i] = (nodesPerLayer[i]);
	}
	
	levelHelper(root, results, index, 0);

	free(nodesPerLayer);
	free(index);
	
	return results;	
}

void postHelper(struct TreeNode *current, int *result, int *index){
	if(current == NULL){
		return;
	}
	
	if(current->left != NULL){
		postHelper(current->left, result, index);
	}
	if(current->right != NULL){
		postHelper(current->right, result, index);	
	}
	result[(*index)++] = current->val;
}

int * postorderTraversal(struct TreeNode *root, int* returnSize){
	int *index = malloc(sizeof(int));
	*returnSize = 0;
	*index = 0;
	size(root, returnSize);
	int *result = malloc(sizeof(int) * (*returnSize));
	postHelper(root, result, index);
	return result;
}

void preHelper(struct TreeNode *current, int *result, int *index){
	if(current == NULL){
		return;
	}
	result[(*index)++] = current->val;
	
	if(current->left != NULL){
		preHelper(current->left, result, index);
	}
	if(current->right != NULL){
		preHelper(current->right, result, index);	
	}
}

int * preorderTraversal(struct TreeNode *root, int* returnSize){
	int *index = malloc(sizeof(int));
	*returnSize = 0;
	*index = 0;
	size(root, returnSize);
	int *result = malloc(sizeof(int) * (*returnSize));
	preHelper(root, result, index);
	free(index);
	return result;
}

void inHelper(struct TreeNode *current, int *result, int *index){
	if(current == NULL){
		return;
	}
	
	if(current->left != NULL){
		inHelper(current->left, result, index);
	}
	
	result[(*index)++] = current->val;
	
	if(current->right != NULL){
		inHelper(current->right, result, index);	
	}
}

int * inorderTraversal(struct TreeNode *root, int* returnSize){
	int *index = malloc(sizeof(int));
	*returnSize = 0;
	*index = 0;
	size(root, returnSize);
	int *result = malloc(sizeof(int) * (*returnSize));
	inHelper(root, result, index);
	free(index);
	return result;
}


void nodeConstructor(struct TreeNode *node, struct TreeNode *left, struct TreeNode *right, int val){
	node->left = left;
	node->right = right;
	node->val = val;
}


int main(){
	//int *nodeCount = malloc(sizeof(int));

	struct TreeNode *a = malloc(sizeof(struct TreeNode));
	struct TreeNode *b = malloc(sizeof(struct TreeNode));
	struct TreeNode *c = malloc(sizeof(struct TreeNode));
	struct TreeNode *d = malloc(sizeof(struct TreeNode));
	struct TreeNode *e = malloc(sizeof(struct TreeNode));
	struct TreeNode *f = malloc(sizeof(struct TreeNode));
	struct TreeNode *g = malloc(sizeof(struct TreeNode));
	struct TreeNode *h = malloc(sizeof(struct TreeNode));

	nodeConstructor(a, b, c, 12);
	nodeConstructor(b, d, e, 21);
	nodeConstructor(c, f, g, 420);
	//nodeConstructor(c, NULL, NULL, 420);
	nodeConstructor(d, NULL, NULL, 69);
	nodeConstructor(e, NULL, NULL, 123);
	nodeConstructor(f, NULL, NULL, 3211);	
	nodeConstructor(g, NULL, h, 881);
	//nodeConstructor(g, NULL, NULL, 881);
	nodeConstructor(h, NULL, NULL, 321);
	
	printf("\n %d \n",hasPathSum(a, 363));

	/*int *returnColumnSize;
	int returnSize;
	
	int **result = levelOrder(a, &returnSize, &returnColumnSize);
	

	printf("result[0][0] = %d\n", result[0][0]);
	printf("*returnSize = %d\n", returnSize);
	fflush(stdout);

	//printf("%d\n", returnColumnSize[0][0]);
	//fflush(stdout);
	
	for(int i = 0; i < returnSize; i++){
		for(int j = 0; j < returnColumnSize[i]; j++){
			printf("result[%d][%d] = %d\n", i, j, result[i][j]);
		}
	}*/
	
	//int *result = postorderTraversal(a, nodeCount);
	//int *result = preorderTraversal(a, nodeCount);
	//int *result = inorderTraversal(a, nodeCount);
	/*for(int i = 0; i < *nodeCount; i++){
		printf("result[%d] = %d\n", i, result[i]);
	}//*/

	
	//free(result);
	//free(nodeCount);

}
