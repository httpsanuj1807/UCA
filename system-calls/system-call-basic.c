#include<stdio.h>
#include<unistd.h>  // unix standard 
#include<fcntl.h>   // file control
#include<errno.h>
#include<stdlib.h>
#include<string.h>

extern int errno;

int main(){

	printf("\nProcess File Descriptor Table\n");
	printf("--------------------------------------\n");
	printf("Descriptor\t Pointer\t Description\n");
	printf("--------------------------------------\n");


	// 0, 1, 2 file descriptors are automatically created in fd table

	printf("%d\t\t %p\t Terminal's Input Device\n", STDIN_FILENO, stdin);
	printf("%d\t\t %p\t Terminal's Output Device\n", STDOUT_FILENO, stdout);
	printf("%d\t\t %p\t Terminal's Error Device\n", STDERR_FILENO, stderr);

	// creating two files, one input and one output create() function use

	// The creat() function in C is used to create a new file or rewrite an existing one. The creat() function creates a file if it doesn't already exist and truncates the file (i.e., empties its contents) if it does exist.

	int inputFileDesc = creat("input-file.txt", 0600);
	int outputFileDesc = creat("output-file.txt", 0600);

	if(inputFileDesc == -1 || outputFileDesc == -1){

    		printf("\nError code: %d\n", errno);
    		perror("Message");
   	 	return 0;

	}

	// The fdopen() function in C is used to associate a file stream with an existing file descriptor. It allows you to take a file descriptor (an integer that represents an open file) and create a FILE pointer

	inputFileDesc = open("input-file.txt", O_RDWR);

	printf("%d\t\t %p\t Input File Descriptor\n", inputFileDesc, fdopen(inputFileDesc, "r"));
	printf("%d\t\t %p\t Output File Descriptor\n", outputFileDesc, fdopen(outputFileDesc, "w"));


	// open() function use 
	// creating new file if not exist, if exist then deleting its content


	// <------------------------- error code below ------------------------------>

	// int testFileDesc = open("test.txt", O_RDWR); // this will give error if we dont have file already

	// int testFileDesc = open("test.txt", O_RDWR);

	// if(testFileDesc == -1){

	//     printf("\nError code: %d\n", errno);
	//     perror("Message");
	//     return 0;
	// }

	// <-------------------------- error code above ------------------------------>
 

	int testFileDesc = open("test.txt", O_RDWR | O_CREAT);

	if(testFileDesc == -1){

    		printf("\nError code: %d\n", errno);
		perror("Message");
    		return 0;
	}	

	printf("%d\t\t %p\t Test File Descriptor\n", testFileDesc, fdopen(testFileDesc, "r"));



	// close() function use

	// <----------------------------- Error code below --------------------------------------->

	// if(close(8) == -1){  // suppose 8 is a file descriptor

	//     printf("\nError closing file, errCode (%d)\n", errno);
	//     perror("Message");

	// }

	// <----------------------------- Error code above --------------------------------------->

	// if(close(testFileDesc) == -1){  

	//     printf("\nError closing file, errCode (%d)\n", errno);
	//     perror("Message");

	// }else{

	//     printf("\nFile closed successfully\n");
	//     printf("%d\t\t %p\t Test File Descriptor\n", testFileDesc, fdopen(testFileDesc, "r"));

	//     if(close(5) == -1){  // closing again to recheck
	//         printf("\nError closing file, errCode (%d)\n", errno);
	//         perror("Message");

	//     }
	// }


	// read( fd, buffer, cnt(in bytes) ) function use
	// return Number of bytes read on success
	// return 0 on reaching the end of file
	// return -1 on error

	char *str = (char*) calloc(500, sizeof(char)); 

	if(str == NULL){

    		printf("\nError code: %d\n", errno);
    		perror("Message");

	}

	int size_read_bytes = read(testFileDesc, str, 500);

	if(size_read_bytes == -1){

    		printf("\nError code: %d\n", errno);
    		perror("Message");
    		return 0;

	}

	printf("\n%s", str);

	printf("\nBytes read %d\n", size_read_bytes);



	// write(fd, buf, cnt) function
	//  returns the number of bytes written on success.
	//  return 0 on reaching the End of File.
	//  return -1 on error.

	strcpy(str, "I love India.");

	int size_write_bytes = write(testFileDesc, str, strlen(str));

	if(size_write_bytes == -1){

    		printf("\nError code: %d\n", errno);
    		perror("Message");
    		return 0;

	}	

	printf("\nBytes wrote %d\n", size_write_bytes);

	return 0;

}
