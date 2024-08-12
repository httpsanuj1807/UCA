#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include <limits.h>



typedef struct Node {
    
    int val;
    struct Node* next;

} Node;

Node *head = NULL;
int N = 0;


void push(int n){

    Node* temp = head;

    head = (Node*) malloc(sizeof(Node)); 
    head -> val = n;
    head -> next = temp;
    N++;

}

int pop(){

    if(N == 0) return INT_MIN;
    Node* temp = head;
    int val = head -> val;
    head = temp -> next;
    N--;
    free(temp);
    return val;

}



bool isEmpty(){

    return N == 0;

}


int size(){

    return N;

}



void test_my_stack(){

    push(3);
    push(10);
    push(20);

    assert(isEmpty() == false);
    assert(size() == 3);
    assert(pop() == 20);
    assert(size() == 2);
    assert(pop() == 10);
    assert(size() == 1);
    assert(pop() == 3);
    assert(size() == 0);
    assert(isEmpty());
    
}


int main(){


    test_my_stack();

    printf("\nSuccess!!\n");

    return 0;

}

