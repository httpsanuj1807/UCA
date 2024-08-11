#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include <limits.h>



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


int main(){


    test_my_stack();

    printf("Success!!\n");

    return 0;

}

