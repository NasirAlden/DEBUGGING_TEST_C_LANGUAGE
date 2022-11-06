#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
// struct to collect counting info about english letters found in a text file.
typedef struct letter {
	char small;
	char big;
	int counter;
	struct letter* next;
	struct letter* prev;
}letter;
//Function to free linked list
void freeList(letter* head) {
	letter* releaseItem;
	letter* runItem = head;
	while (runItem != NULL) {
		releaseItem = runItem;
		runItem = runItem->next;
		free(releaseItem);
	}
}
int main()
{
	//Next two string represents all the english alphabets (small and capital)
	char* smallAlpha = "abcdefghijklmnopqrstuvwxyz";
	char* bigAlpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int lettersCountArr[26] = { 0 };
	char readChar, ch;
	FILE* f;
	f = fopen("myFile.txt", "r");
	// Display the content of myFile.txt and count letters
	printf("the content of myFile.txt :\n");
	while ((readChar = fgetc(f)) != EOF) {
		printf("%c", readChar);
		for (int i = 0; i < strlen(smallAlpha); ++i) {
			if (readChar == smallAlpha[i] || readChar == bigAlpha[i])
				lettersCountArr[i]++;
		}
	}
	fclose(f);
	// Build Linked list from file content
	// Every node represent English letter (small and big).
	letter* HEAD = NULL;
	letter* TAIL = NULL;
	for (int j = 0; j < strlen(smallAlpha); ++j) {
		letter* letterItem = (letter*)malloc(sizeof(letter));
		if (!letterItem) {
			puts("Error Allocating Memory!");
			exit(1);
		}
		letterItem->small = 'a' + j;
		letterItem->big = 'A' + j;
		letterItem->counter = lettersCountArr[j];
		letterItem->next = NULL;
		letterItem->prev = NULL;
		// Creating the linked list
		if (HEAD == NULL) {
			HEAD = TAIL = letterItem;
		}
		else {
			TAIL->next = letterItem;
			letterItem->prev = TAIL;
			TAIL = letterItem;
			TAIL->next = NULL;
		
		}
		
	}
	return 0;
}