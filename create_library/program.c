#include <stdio.h>
#include "func.h"

int main(){

	printf("%d + %d = %d", 4, 5, add(4, 5));
	printf("\n%d - %d = %d\n", 7, 3, sub(7, 3));

	return 0;

}
