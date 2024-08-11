#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/time.h>


int *arr = NULL;
int N = 0;
int max_size = 1;

void resize(int new_size){

    int *new_arr = (int *) malloc(new_size * sizeof(int));

    for(int i = 0 ; i < N; i++){

        new_arr[i] = arr[i];

    }

    free(arr);

    arr = new_arr;

    max_size = new_size;

}

void push(int n){

    if(arr == NULL){

        arr = (int*) malloc(max_size * sizeof(int));

    } 
    else if(N == max_size){

        resize(2 * max_size);

    }

    arr[N++] = n;

}

bool isEmpty(){

    return N == 0;

}

int pop(){

    if(isEmpty()) return INT_MIN;
    int num = arr[--N];
    if(N > 0 &&  N == max_size / 4){

        resize(max_size / 2);
        max_size /= 2;

    }

    return num;

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

    free(arr);
    
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


    free(arr);
    arr = NULL;
    N = 0;
    max_size = 1;

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

