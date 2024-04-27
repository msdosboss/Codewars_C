#include <stdlib.h>
#include <stdio.h>

struct TreeNode{
	int val; 
	struct TreeNode *left;
	struct TreeNode *right;
	
};

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

void helper(struct TreeNode *current, int *result, int *index){
	if(current == NULL){
		return;
	}
	
	if(current->left != NULL){
		helper(current->left, result, index);
	}
	if(current->right != NULL){
		helper(current->right, result, index);	
	}
	result[(*index)++] = current->val;
}

int * postorderTraversal(struct TreeNode *root, int* returnSize){
	int *index = malloc(sizeof(int));
	*returnSize = 0;
	*index = 0;
	size(root, returnSize);
	int *result = malloc(sizeof(int) * (*returnSize));
	helper(root, result, index);
	return result;
}

void nodeConstructor(struct TreeNode *node, struct TreeNode *left, struct TreeNode *right, int val){
	node->left = left;
	node->right = right;
	node->val = val;
}

int main(){
	int *nodeCount = malloc(sizeof(int));
		
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
	nodeConstructor(d, NULL, NULL, 69);
	nodeConstructor(e, NULL, NULL, 123);
	nodeConstructor(f, NULL, NULL, 321);
	nodeConstructor(g, NULL, h, 881);
	nodeConstructor(h, NULL, NULL, 321);
	
	int *result = postorderTraversal(a, nodeCount);

	for(int i = 0; i < *nodeCount; i++){
		printf("result[%d] = %d\n", i, result[i]);
	}


}
