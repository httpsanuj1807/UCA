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

Node* head = NULL;
Node* tail = NULL;
int N = 0;


void push(int n){

    Node* oldTail = tail;

    tail = (Node*) malloc(sizeof(Node));
    tail -> val = n;
    tail -> next = NULL;

    if(N == 0) head = tail;
    else oldTail -> next = tail;
    N++;

}

int pop(){

   if(N == 0) return INT_MIN;
   Node* temp = head;
   int val = temp -> val;
   head = temp -> next;
   N--;
   if(N == 0) tail = NULL;
   free(temp);
   return val;

}



bool isEmpty(){

    return N == 0;

}


int size(){

    return N;

}



void test_my_queue(){

    push(3);
    push(10);
    push(20);

    assert(isEmpty() == false);
    assert(size() == 3);
    assert(pop() == 3);
    assert(size() == 2);
    assert(pop() == 10);
    assert(size() == 1);
    assert(pop() == 20);
    assert(size() == 0);
    assert(isEmpty());

    
}

long long curr_time_millis(){

    struct timeval time;
    gettimeofday(&time, NULL);
    return time.tv_sec * 1000LL + time.tv_usec / 1000;

}

void track_behaviour(int queue_size){

    long long start_time, end_time;

    start_time = curr_time_millis();

    for(int i = 0; i < queue_size ; i++){

        push(i);

    }

    end_time = curr_time_millis();

    long long push_time = end_time - start_time;


    start_time = curr_time_millis();


    for(int i = 0; i < queue_size ; i++){

        pop();

    }

    end_time = curr_time_millis();

    long long pop_time = end_time - start_time;

    printf("%d\t\t %lld\t\t %lld\n", queue_size, push_time, pop_time);

    N = 0;
    head = NULL;
    tail = NULL;

}



int main(){


    test_my_queue();

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
// 100000           19              14
// 200000           40              22
// 400000           87              37
// 800000           178             86
// 1600000          299             154
// 3200000          492             207
// 6400000          803             348
