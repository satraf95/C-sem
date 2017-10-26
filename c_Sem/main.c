/*
 * main.c
 *
 *  Created on: 24. 10. 2017
 *      Author: frantisek
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

typedef struct Node{
	char vertex[32];
	int value;
	struct Node *next;
}Node;




void addVertexToList (Node **head, char *vertex, int value){
	Node *v, *temp;

	temp = malloc(sizeof(Node));
	strcpy(temp->vertex, vertex);
	temp->value = value;
	temp->next = NULL;

	if (*head){
		v = *head;
		while(v->next){
			v = v->next;
		}
		v->next = temp;
	}else{
		*head = temp;
	}
}
int main(int argc, char *argv[]){
	FILE *stream;
	char *record;
	int count = 0;
	//int i = 0;
	char data[BUFFER_SIZE];
	//char ddata[BUFFER_SIZE];
	const char delims[2] = ";";



	//malloc(sizeof(data));

//	if (argc != 2){
//		printf("Usage of: <file>\n ", argv[0]);
//	}

	stream = fopen("File.csv", "r");
	if(stream == NULL){
		perror("failed to open");
		exit(EXIT_FAILURE);
	}

	while((fgets(data, BUFFER_SIZE, stream))){
		//record = strtok(data, delims))
			//printf("%s \n", data);
			record = strtok(data, delims);
			while(record != NULL){
				printf(" %s \n", record);
				record = strtok(NULL, delims);
			}
			//record = strtok(NULL, delims);
			//record = strtok(NULL, delims);



	}

//	while((nread = getline(&line, &len, stream)) != -1){
//		count++;
//		//record = strtok(nread, ';');
//		//data[i] = record;
//		//i++;
//		printf("Retrieved line of length %zu:\n", nread);
//		//printf("\n %s \n", record);
//		fwrite(line, nread, 1, stdout);
//
//	}
	printf("\nline count: %d", count);
	fclose(stream);
	exit(EXIT_SUCCESS);

}

