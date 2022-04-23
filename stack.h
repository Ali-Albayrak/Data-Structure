#include <stdio.h>
#define MAX 100

typedef struct stack{
    int data[MAX];
    int top;
}stack;

int is_empty(stack s);
void push(stack *s, char data);
int pop(stack *s);
int peek(stack s);

int is_empty(stack s){
    if(s.top == -1)
        return 1;
    return 0;
}

void push(stack *s, int data){
    if(s->top == MAX-1){
        printf("stack is full!!\n");
        return;
    }
    s->data[++s->top] = data;
}

int pop(stack *s){
    if(is_empty(*s)){
        printf("stack is empty!!\n");
        return 0;
    }
    return s->data[s->top--];
}

int peek(stack s){
    if(is_empty(s)){
        printf("stack is empty!!\n");
        return 0;
    }
    return s.data[s.top];
}

void display(stack s){
    int i;
    if(is_empty(s)){
        printf("stack is empty!!\n");
        return;
    }
    for(i=s.top;i>=0;i--){
        printf("%3c", s.data[i]);
    }
}