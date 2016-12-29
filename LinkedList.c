#include<stdio.h>
#include<stdlib.h>

struct LinkedList{
	int data;
	struct LinkedList *next;
};

void insert(struct LinkedList **head, int data, int pos){
	if(pos <= 0)
		return;
	int counter = 1;
	struct LinkedList *newNode = (struct LinkedList *) malloc (sizeof(struct LinkedList));
	if(!newNode)
		return;
	if(pos == 1){
		newNode->data = data;
		newNode->next = *head;
		*head = newNode;
		return;
	}
	if(!(*head))
		return;
	struct LinkedList *curr = *head;
	while(counter < pos-1){
		if(curr->next){
			curr = curr->next;
			counter++;
		}
		else
			return;
	}
	newNode->data = data;
	newNode->next = curr->next;
	curr->next = newNode;
	return;
}

void delete(struct LinkedList **head, int pos){
	if(pos <= 0)
		return;
	if(!(*head))
		return;
	int counter = 1;
	struct LinkedList *curr = *head;
	if(pos == 1){
		*head = curr->next;
		free(curr);
		return;
	}
	while(counter < pos-1){
		if(curr->next)
			curr = curr->next;
		if(!curr->next)
			return;
		counter++;
	}
	if(!curr->next)
			return;
	struct LinkedList *temp = curr->next;
	curr->next = (curr->next)->next;
	free(temp);
}

void printList(struct LinkedList *head){
	struct LinkedList *curr = head;
	if(curr){
		printf("%d ", curr->data);
		curr = curr->next;
	}
	while(curr){
		printf("-> %d", curr->data);
		curr = curr->next;
	}
}

int listLength(struct LinkedList *head){
	int length = 0;
	struct LinkedList *curr = head;
	while(curr){
		curr = curr->next;
		length++;
	}
	return length;
}

int main(){
	int i, data, pos;
	char term;
	struct LinkedList *head = NULL;
	while(1){
		printf("\n1. Insert \n2. Delete \n3. Print \n4. Length \n5. Exit");
		printf("\nEnter your choice: ");
		if(scanf("%d%c", &i, &term) != 2 || term != '\n'){
    				printf("failure\n");
    				fflush(stdin);
    			}
		if(i==1){
				printf("\nValue to be inserted: ");
				if(scanf("%d%c", &data, &term) != 2 || term != '\n'){
    				printf("failure\n");
    				fflush(stdin);
    			}
				//else
    				//printf("valid integer followed by enter key\n");
				printf("\nPosition to be inserted: ");
				if(scanf("%d%c", &pos, &term) != 2 || term != '\n'){
    				printf("failure\n");
    				fflush(stdin);
    			}
				insert(&head, data, pos);
		}
		else if(i==2){
				if(scanf("%d%c", &pos, &term) != 2 || term != '\n'){
    				printf("failure\n");
    				fflush(stdin);
    			}
				delete(&head, pos);
		}
		else if(i==3){
				printList(head);
		}
		else if(i==4){
				printf("\nLength of List: %d", listLength(head));
		}
		else
			break;
	}
	return 0;
}
