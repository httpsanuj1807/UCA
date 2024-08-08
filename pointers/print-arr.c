#include <stdio.h>

int main() {

    int arr[] = {1, 2, 3, 4};
    int *p = arr;
    int n = 4;

    for(int i = 0; i < n + 2 ; i++){
    
	printf("%d\n", arr[i]);
    
    }

    return 0;

}
