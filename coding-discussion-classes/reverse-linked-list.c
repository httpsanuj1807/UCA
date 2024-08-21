#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {

    int val;
    struct Node* next;

} Node;

Node* head = NULL;
int N = 0;


void push(int n){

    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode -> val = n;
    newNode -> next = head;
    head = newNode;
    N++;

}



int size(){

    return N;

}

void printLinkedList(Node* head){

    printf("Printing : ");
    Node* temp = head;

    while(temp){

        printf("%d ", temp -> val);
        temp = temp -> next;

    }
    printf("\n");

}


Node* reverse_using_recursion(Node* head){

    if(head == NULL || head -> next == NULL){

        return head;

    }

    Node* newHead = reverse_using_recursion(head -> next);
    Node* front = head -> next;
    front -> next = head;
    head -> next = NULL;
    return newHead;

}


Node* reverse_using_iteration(Node* head){

    Node* temp = head;
    Node* prev = NULL;
    Node* front = NULL;

    while(temp){

        front = temp -> next;
        temp -> next = prev;
        prev = temp;
        temp = front;

    }

    return prev;

}

int main(){

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = 8;

    for(int i = 0; i < n; i++){

        push(arr[i]);

    }

    printLinkedList(head);
    printf("\nReversing using iteration method\n");
    head = reverse_using_iteration(head);
    printLinkedList(head);
    printf("\nReversing using recursion method\n");
    head = reverse_using_recursion(head);
    printLinkedList(head);
    
    return 0;
}
