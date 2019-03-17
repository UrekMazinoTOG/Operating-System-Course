#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include "slist.h"

size_t countDiv(node* head, int8_t base);

int main() 
{ 
	// Open numbers.txt file
	FILE* inputFile = NULL;
	inputFile = fopen("numbers.txt", "r");
	// Check error of fopen()
	if(inputFile == NULL) {
		perror("Failed to read numbers.txt");
		exit(EXIT_FAILURE);
	}
	// Read the file and insert data into the list
	node* list = NULL; T temp = 0; 

	while(!feof(inputFile)) 
		if(fscanf(inputFile, "%li", &temp) == true)
			list = push_front(list, temp);

	// Close numbers.txt file
	fclose(inputFile);

	// Creating child process
	int P1, P2;

	P1 = fork();

	if(P1 == 0) {

		P2 = fork();

		if(P2 == 0) {
			printf("%li\n", countDiv(list, 2));
			deal(list);
			exit(EXIT_SUCCESS);
		}
		else {
			printf("%li\n", countDiv(list, 3));
			deal(list);
			exit(EXIT_SUCCESS);
		}
	}
	else {
		printf("%li\n", countDiv(list, 5));
		deal(list);
		wait(NULL);
		exit(EXIT_SUCCESS);
	}

	return EXIT_SUCCESS;
}

// Count the numbers in the list that are divisible by base(N)
size_t countDiv(node* head, int8_t base)
{
	int count = 0;
	
	for(node *pNode = head; pNode != NULL; pNode = pNode->next)
	if(pNode->data % base == 0) ++count;

	return count;
}

