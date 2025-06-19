#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node **head, int data){
    struct Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void deleteFromBeginning(struct Node **head){
    if(*head==NULL){
        printf("List Empty\n");
        return;
    }
    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void printList(struct Node *head){
    while(head!=NULL){
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main(){
    struct Node *node = NULL;
    insertAtBeginning(&node, 10);
    insertAtBeginning(&node, 20);
    printList(node);
    deleteFromBeginning(&node);
    printList(node);
}