#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	struct Node *next;
	int value;
}Node;

void print(struct Node* n){

	while (n->next != NULL) {
		n = n->next;
		printf(" %d ", n->value);
	}
	printf("\n");
}

void append(Node *head, int val){
    Node *tmp = head;
    Node *newnode;
    
	newnode = (struct Node*)malloc(sizeof(struct Node));

    
//    newnode->value = val;
//    printf("Test1\n");
//	newnode->next = 0;
//    printf("Test2\n");
    // printf("head = %d\n",head.value);
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
        // printf("head = %d\n",head.value);
    }
    // printf("%d\n",tmp->value);
//    printf("Test3\n");
    
    tmp->next = newnode;
//    printf("Test4\n");
    newnode->value = val;
    newnode->next = NULL;
    // newnode->next = NULL;
    
}

int del(Node *head, int val){ // returns -1 if couldn't find index otherwise returns 0
	Node *tmp, *tmp2;
    tmp = (struct Node*)malloc(sizeof(struct Node));
    tmp2 = (struct Node*)malloc(sizeof(struct Node));
    
    tmp = head;
    tmp2 = head;
    
    while( tmp != NULL && tmp->value != val){
    	tmp2 = tmp;
		tmp = tmp->next; 
	}
	
	if(tmp == NULL){
		return -1;
	}
	tmp2->next = tmp->next;
	return 0;
}

int del_index(Node *head, int index){ // returns -1 if couldn't find index otherwise returns 0
	int i = 0;
	Node *tmp, *tmp2;
    tmp = (struct Node*)malloc(sizeof(struct Node));
    tmp2 = (struct Node*)malloc(sizeof(struct Node));
    
    if(i<0){
    	return -1;
	}
    
    tmp = head;
    tmp2 = head;
    
    while( tmp != NULL && i <= index){
    	tmp2 = tmp;
		tmp = tmp->next;
		i++;
	}
	
	if(tmp == NULL){
		return -1;
	}
	tmp2->next = tmp->next; 
	return 0;   
}

void insert(Node *head,int val, int index){
	int i = 0;
	Node *newnode;
	Node *tmp, *tmp2;
	newnode = (struct Node*)malloc(sizeof(struct Node));
	
	if(index < 0){
		return;
	}
	
	tmp = head;
	tmp2 = tmp;
	
    
    while(tmp != NULL && i<=index){
    	tmp2 = tmp;
    	tmp = tmp->next;
    	i++;
	}
	
	newnode->next = tmp;
	newnode->value = val;
	
	tmp2->next = newnode;
	
}

int find_by_val(Node *head, int val){ // returns -1 if couldn't found otherwise returns 1
	Node *newnode;
	Node *tmp;
	newnode = (struct Node*)malloc(sizeof(struct Node));
	
	tmp = head;	
    
    while(tmp != NULL && tmp->value != val){
    	tmp = tmp->next;
	}
	if (tmp != NULL){
		return 1;
	}
	return -1;
}

int find_by_index(Node *head, int index){ // returns -1 if couldn't found otherwise returns value of index
	int i = 0;
	Node *newnode;
	Node *tmp;
	newnode = (struct Node*)malloc(sizeof(struct Node));
	
	if(index < 0){
		return -1;
	}
	
	tmp = head;	
    
    while(tmp != NULL && i<=index){
    	tmp = tmp->next;
    	i++;
	}
	if (tmp != NULL){
		return (tmp->value);
	}
	
	return -1;
}

/*
int main(){

	Node *head = NULL;
	head = (struct Node*)malloc(sizeof(struct Node));
	
	head->next = NULL;
	print(head);
	insert(head,4,0);
	append(head,7);
	append(head,14);
	append(head,2);
	print(head);
	insert(head,4,0);
	print(head);
	append(head,5);
	del(head, 14);
	print(head);
	del_index(head, 6);
	print(head);
	
	printf("\nfind = %d\n", find_by_val(head, 11));

	printf("\nfind = %d\n", find_by_index(head, -0));
	
	
	return 0;
}
*/
