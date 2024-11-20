#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
	int data;
	int priority;
	struct Node* next;
} Node;
Node* newNode(int data, int priority) {
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->priority = priority;
	temp->next = NULL;
	return temp;
}
Node* dequeue(Node** head) {
	if (*head == NULL) {
		return NULL;
	}
	Node* temp = *head;
	*head = (*head)->next;
	return temp;
}
void enqueue(Node** head, int data, int priority) {
	Node* start = *head;
	Node* temp = newNode(data, priority);

	if (*head == NULL || (*head)->priority > priority) {
		temp->next = *head;
		*head = temp;
	} else {
		while (start->next != NULL && start->next->priority <= priority) {
			start = start->next;
		}
		temp->next = start->next;
		start->next = temp;
	}
}
void printQueue(Node* head) {
	while (head != NULL) {
		printf("%d (%d)", head->data, head->priority);
		head = head->next;
		if (head != NULL) {
			printf(" ");
		}
	}
	printf("\n");
}
int main() {
	int numOperations;
	scanf("%d", &numOperations);
	Node* pq = NULL;
	for (int i = 0; i < numOperations; i++) {
		int operation, data, priority;
		scanf("%d", &operation);
		if (operation == 1) {  // Enqueue operation
			scanf("%d %d", &data, &priority);
			enqueue(&pq, data, priority);
		} else if (operation == 2) {  // Dequeue operation
			Node* dequeuedNode = dequeue(&pq);
			free(dequeuedNode);
		}
	}
	if (pq == NULL) {
		printf("Empty\n");
	} else {
		printQueue(pq);
	}
	return 0;
}

