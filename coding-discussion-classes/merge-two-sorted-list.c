#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

Node* head1 = NULL;
int N1 = 0;

Node* head2 = NULL;
int N2 = 0;

void push(int n, Node** head, int* N) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode -> val = n;
    newNode -> next = *head;
    *head = newNode;
    (*N)++;
}

void printLinkedList(Node* head) {
    printf("Printing: ");
    Node* temp = head;
    while (temp) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

Node* merge(Node* head1, Node* head2){

    Node* temp1 = head1;
    Node* temp2 = head2;    
    Node* dummy = (Node*) malloc(sizeof(Node));
    dummy -> val = -1;
    dummy -> next = NULL;
    Node* result = dummy;

    while(temp1 != NULL && temp2 != NULL){

        if(temp1 -> val <= temp2 -> val){

            dummy -> next = temp1;
            dummy = temp1;
            temp1 = temp1 -> next;

        }
        else{

            dummy -> next = temp2;
            dummy = temp2;
            temp2 = temp2 -> next;

        }

    }

    while(temp1 != NULL){

        dummy -> next = temp1;
        dummy = temp1;
        temp1 = temp1 -> next;

    }

    while(temp2 != NULL){

        dummy -> next = temp2;
        dummy = temp2;
        temp2 = temp2 -> next;

    }

    return result -> next;

}

int main() {
    int arr1[] = {12, 5, 3, 1};
    int arr2[] = {22, 16, 11, 8 , 3, 0};
    int n1 = 4;
    int n2 = 6;

    for (int i = 0; i < n1; i++) {
        push(arr1[i], &head1, &N1);
    }

    for (int i = 0; i < n2; i++) {
        push(arr2[i], &head2, &N2);
    }

    printLinkedList(head1);
    printLinkedList(head2);
    Node* mergeHead = merge(head1, head2);
    printLinkedList(mergeHead);

    return 0;
}

