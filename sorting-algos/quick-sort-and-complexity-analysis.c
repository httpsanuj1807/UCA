#include <stdio.h>
#include <assert.h>  
#include <stdlib.h>  // srand(), malloc(), free()
#include <sys/time.h> // gettimeofday()
#include <time.h>
void exch(int arr[], int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}   


void quick_recursive_algo(int arr[], int left, int right){

    if(left >= right) return;

    int pivot = arr[left];
    int i = left + 1;

    for(int j = i; j <= right; j++){

        if(arr[j] < pivot) exch(arr, i++, j);

    }

    exch(arr, left, --i);
    quick_recursive_algo(arr, left, i - 1);
    quick_recursive_algo(arr, i + 1, right);


}

void quickSort(int arr[], int n){

    quick_recursive_algo(arr, 0, n - 1);

}

long long calculate_runtime(int arr[], int n) {
    
    struct timeval before;
    gettimeofday(&before, NULL);

    long long before_millis = before.tv_sec*1000LL + before.tv_usec/1000LL;

    quickSort(arr, n);

    struct timeval after;
    gettimeofday(&after, NULL);

    long long after_millis = after.tv_sec*1000LL + after.tv_usec/1000LL;    

    return after_millis - before_millis;
}


void test_quick_sort(){

    int arr[] = {4,1,5,8,0,2,11};
    int expected_output[] = {0,1,2,4,5,8,11};
    int n = 7;

    quickSort(arr, n);

    for(int i = 0; i < n; i++) assert(arr[i] == expected_output[i]);

    printf("Success, all test passed\n");

}


int main(){

    test_quick_sort();

    // random input test

    srand(time(NULL));

    int k = 10000;
    int *arr1 = (int *) malloc(k * sizeof(int));

    for(int i = 0; i < k; i++) arr1[i] = rand();
    long long time_taken_random_small = calculate_runtime(arr1, k);

    
    int *arr2 = (int *) malloc((2*k) * sizeof(int));

    for(int i = 0; i < (2 * k); i++) arr2[i] = rand();
    long long time_taken_random_larger = calculate_runtime(arr2, 2*k);

    int *arr3 = (int *) malloc((3*k) * sizeof(int));

    for(int i = 0; i < (3 * k); i++) arr3[i] = rand();
    long long time_taken_random_largest = calculate_runtime(arr3, 3*k);


    // worst case - asc


    for(int i = 0; i < k; i++) arr1[i] = i;
    long long time_taken_worst_asc_small = calculate_runtime(arr1, k);

    for(int i = 0; i < (2 * k); i++) arr2[i] = i;
    long long time_taken_worst_asc_larger = calculate_runtime(arr2, 2*k);

    for(int i = 0; i < (3 * k); i++) arr3[i] = i;
    long long time_taken_worst_asc_largest = calculate_runtime(arr3, 3*k);


    // worst case - desc

    for(int i = 0; i < k; i++) arr1[i] = k - i - 1;
    long long time_taken_worst_desc_small = calculate_runtime(arr1, k);

    for(int i = 0 ; i < k; i++) arr2[i] = (2*k) - i - 1;
    long long time_taken_worst_desc_larger = calculate_runtime(arr2, 2*k);

    for(int i = 0; i < k; i++) arr3[i] = (3*k) - i - 1;
    long long time_taken_worst_desc_largest = calculate_runtime(arr3, 3*k);


    printf("Sample Size\tRandom Time\tAsc Time\tDesc Time\n");
    printf("%d\t\t%lld\t\t%lld\t\t%lld\n", k, time_taken_random_small, time_taken_worst_asc_small, time_taken_worst_desc_small);
    printf("%d\t\t%lld\t\t%lld\t\t%lld\n", 2*k, time_taken_random_larger, time_taken_worst_asc_larger, time_taken_worst_desc_larger);
    printf("%d\t\t%lld\t\t%lld\t\t%lld\n", 3*k, time_taken_random_largest, time_taken_worst_asc_largest, time_taken_worst_desc_largest);
    

    
    free(arr1);
    free(arr2);


    return 0;

}
