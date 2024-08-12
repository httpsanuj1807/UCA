#include <stdio.h>

int add(int a, int b){

    return a + b;

}

int sub(int a, int b){

    return a - b;

}

int div(int a, int b){

    return a / b;

}

int mul(int a, int b){

    return a * b;

}

void perform_operation(int a, int b, int (*func)(int a, int b)){

	printf("%d\n",  func(a, b));


}

int main(){
	
	int (*funcPtr) (int, int) = mul;
	perform_operation(5, 3, mul);


	return 0;

}
