#include <stdio.h>
#include <stdbool.h>

void exch(int arr[], int i, int j){

    int temp = arr[i];

    arr[i] = arr[j];
    arr[j] = temp;
}

void bubbleSort(int arr[], int n, bool (*sortMethod)(int a, int b)){

    for(int i = n - 1 ; i > 0 ; i--){

        for(int j = 0; j < i; j++){

            if(sortMethod(arr[j], arr[j + 1])){

                exch(arr, j , j + 1);

            }

        }


    }

}

bool sortAsc(int a, int b){

    return a > b;

}



bool sortDesc(int a, int b){

    return a < b;

}



int main(){

    int arr[5] = {3, 2,7,1,11};

    bubbleSort(arr, 5, sortAsc);

    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;

}
