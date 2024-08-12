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

int valAtIdx(int idx){

    if(idx < 0 || idx >= N) return INT_MIN;

    Node* temp = head;
    int curr = 0;

    while(curr++ < idx) temp = temp -> next;

    return temp -> val;

}

int removeAtIdx(int idx){

    if(idx < 0 || idx >= N) return INT_MIN;

    Node* curr = head;
    Node* prev = NULL;
    int k = 0;

    while(k++ < idx){

        prev = curr;
        curr = curr -> next;

    }

    int val = curr -> val;

    if(prev == NULL) head = head -> next;
    else prev -> next = curr -> next;

    free(curr);
    N--;
    return val;
    
}

bool isEmpty(){

    return N == 0;

}

int size(){

    return N;

}

void testLinkedList(){

    push(3);
    push(10);
    push(20);

    assert(isEmpty() == false);
    assert(size() == 3);
    assert(valAtIdx(0) == 20);
    assert(valAtIdx(1) == 10);
    assert(valAtIdx(2) == 3);
    assert(removeAtIdx(1) == 10);
    assert(size() == 2);
    assert(valAtIdx(0) == 20);
    assert(valAtIdx(1) == 3);
    assert(removeAtIdx(0) == 20);
    assert(size() == 1);
    assert(valAtIdx(0) == 3);
    assert(removeAtIdx(0) == 3);
    assert(size() == 0);
    assert(isEmpty());


}


int main(){


    testLinkedList();

    printf("Success, All test passed.\n");

    return 0;
}
