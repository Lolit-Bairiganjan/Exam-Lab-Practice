#include <stdio.h>
#define MAX 3

int stack[MAX];
int top = -1;
void push(int data){
    if(top==MAX-1){
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = data;
}

void pop(){
    if(top==-1){
        printf("Stack Underflow!\n");
        return;
    }
    top--;
}

void peek(){
    if(top==-1){
        printf("Stack Empty!\n");
        return;
    }
    printf("The top element is: %d\n", stack[top]);
}

int isFull(){
    if(top==MAX-1){
        printf("Stack Full!\n");
        return 1;
    }
    return 0;
}

int isEmpty(){
    if(top==-1){
        printf("Stack Empty!\n");
        return 1;
    }
    return 0;
}

int main(){
    isEmpty();
    push(10);
    peek();
    push(20);
    peek();
    push(30);
    peek();
    isFull();
    push(40);
}