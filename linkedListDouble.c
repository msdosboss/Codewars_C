//https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/description/?envType=daily-question&envId=2024-05-07
#include <stdio.h>
#include <stdlib.h>


struct ListNode {
	int val;
	struct ListNode *next;
};



struct ListNode *doubleIt(struct ListNode *head){
	int arraySize = 0;
	struct ListNode *current;
	struct ListNode *root;
	root = malloc(sizeof(struct ListNode));
	current = head;

	while(current != NULL){
		arraySize++;
		current = current->next;
	}
	int *doubledNumber = malloc(sizeof(int) * (arraySize + 1));
	
	printf("arraySize = %d\n", arraySize);
	current = head;
	
	for(int i = 0; i < arraySize; i++){
		doubledNumber[i] = 0;
	}
	
	
	int ii = 1;
	while(current != NULL){
		printf("current->val = %d\n", current->val);
		doubledNumber[ii++] = (current->val * 2);
	
		if(doubledNumber[ii - 1] >= 10){
			doubledNumber[ii - 1] %= 10;
			doubledNumber[ii - 2]++;
		}
		current = current->next;
	}
	
	
	for(int i = 0; i < arraySize + 1; i++){
		printf("doubledNumber[%d] = %d\n", i, doubledNumber[i]);
	}

	current = root;

	for(int i = ((doubledNumber[0] == 0) ? 1 : 0); i < arraySize; i++){
		printf("i = %d\n", i);
		current->val = doubledNumber[i];
		current->next = malloc(sizeof(struct ListNode));
		current = current->next;
	}
	
	current->val = doubledNumber[arraySize];
	current->next = NULL;
	return root;
}

int main(){
	struct ListNode *root;
	struct ListNode *current;
	root = malloc(sizeof(struct ListNode));
	root->val = 1;
	root->next = malloc(sizeof(struct ListNode));
	current = root->next;
	current->val = 6;
	current->next = malloc(sizeof(struct ListNode));
	current = current->next;
	current->val = 3;
	current->next = NULL;
	struct ListNode *doubled;
	doubled = doubleIt(root);
	
	while(doubled != NULL){
		printf("%d\n", doubled->val);
		doubled = doubled->next;
	}
	
	return 0;
}
