#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node {
	char data[100];
	struct Node* next;
	struct Node* prev;
} Node;

Node* createNode(char* data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	strcpy(newNode->data, data);
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

Node* split(Node* head) {
	Node* fast = head;
	Node* slow = head;
	while (fast->next && fast->next->next) {
		fast = fast->next->next;
		slow = slow->next;
	}
	Node* temp = slow->next;
	slow->next = NULL;
	return temp;
}
Node* merge(Node* first, Node* second) {
	if (!first) return second;
	if (!second) return first;
	if (strcmp(first->data, second->data) < 0) {
		first->next = merge(first->next, second);
		first->next->prev = first;
		first->prev = NULL;
		return first;
	} else {
		second->next = merge(first, second->next);
		second->next->prev = second;
		second->prev = NULL;
		return second;
	}
}
Node* mergeSortUtil(Node* head) {
	if (!head || !head->next) return head;
	Node* second = split(head);
	head = mergeSortUtil(head);
	second = mergeSortUtil(second);
	return merge(head, second);
}

char* listToString(Node* head) {
	static char result[10000];
	result[0] = '\0';
	while (head) {
		strcat(result, head->data);
		if (head->next) {
			strcat(result, " -> ");
		}
		head = head->next;
	}
	return result;
}

char * mergeSort(char *Arr[], int ArrLen) {
	if (ArrLen == 0) {
		static char empty[] = "Empty";
		return empty;
	}
	Node* head = createNode(Arr[0]);
	Node* current = head;
	for (int i = 1; i < ArrLen; i++) {
		current->next = createNode(Arr[i]);
		current->next->prev = current;
		current = current->next;
	}
	head = mergeSortUtil(head);
	return listToString(head);
}
int readStringArray(char *argsArray, char *arr[]) {
	int col = 0;
	char *token = strtok(argsArray, ",");
	while (token != NULL) {
		arr[col] = token;
		token = strtok(NULL, ",");
		col++;
	}
	return col;
}
int main(int argc, char *argv[]) {
	char *Arr[strlen(argv[1])];
	int ArrLen = readStringArray(argv[1], Arr);
	printf("%s\n", mergeSort(Arr, ArrLen));
	return 0;
}