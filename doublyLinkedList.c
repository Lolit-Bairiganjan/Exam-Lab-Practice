#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node* createNode(int data){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertAtBeginning(struct Node **node, int data){
    struct Node *newNode = createNode(data);
    if(*node==NULL){
        *node = newNode;
        return;
    }
    newNode->next = *node;
    (*node)->prev = newNode;
    *node = newNode;
}

void printList(struct Node *node){
    printf("Forward Order: \n");
    while(node->next!=NULL){
        printf("%d->", node->data);
        node = node->next;
    }
    printf("%d->", node->data);
    printf("NULL\n");
    printf("Reverse Order: \n");
    while(node!=NULL){
        printf("%d->", node->data);
        node = node->prev;
    }
    printf("NULL\n");
}

int main(){
    struct Node *node = NULL;
    insertAtBeginning(&node, 10);
    insertAtBeginning(&node, 20);
    insertAtBeginning(&node, 30);
    printList(node);
}