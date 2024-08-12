#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/time.h>


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

long long curr_time_millis(){

    struct timeval time;
    gettimeofday(&time, NULL);
    return time.tv_sec * 1000LL + time.tv_usec / 1000;

}

void track_behaviour(int stack_size){

    long long start_time, end_time;

    start_time = curr_time_millis();

    for(int i = 0; i < stack_size ; i++){

        push(i);

    }

    end_time = curr_time_millis();

    long long push_time = end_time - start_time;


    start_time = curr_time_millis();


    for(int i = 0; i < stack_size ; i++){

        pop();

    }

    end_time = curr_time_millis();

    long long pop_time = end_time - start_time;

    printf("%d\t\t %lld\t\t %lld\n", stack_size, push_time, pop_time);

    N = 0;
    head = NULL;

}



int main(){


    test_my_stack();

    printf("\nSuccess!! All tests passed.\n\n");

    printf("Sample Size\t Push Time\t Pop Time\n");



    track_behaviour(100000);
    track_behaviour(200000);
    track_behaviour(400000);
    track_behaviour(800000);
    track_behaviour(1600000);
    track_behaviour(3200000);
    track_behaviour(6400000);
    
    


    return 0;

}


// Sample Size      Push Time       Pop Time
// 100000           20              12
// 200000           40              19
// 400000           67              32
// 800000           109             48
// 1600000          137             75
// 3200000          372             164
// 6400000          703             416
