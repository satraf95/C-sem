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
	char vertex1[32];
	char value[64];
	struct Node *next;
}Node;




void addVertexToList (Node **head, char *vertex, char *vertex1, char *value){

	Node *v, *temp;

	temp = malloc(sizeof(Node));
	strcpy(temp->vertex, vertex);
	strcpy(temp->vertex1, vertex1);
	strcpy(temp->value, value);
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

void printList (Node *head){
	while(head){
		printf("Vertex:%s %s %s\n", head->vertex, head->vertex1, head->value);
		head = head->next;
	}
}

void deleteChars(char *string, char delims){
	char *pr = string, *pw = string;
	while(*pr){
		*pw = *pr++;
		pw += (*pw != delims);
	}
	*pw = '\0';
}

int main(int argc, char *argv[]){
	FILE *stream;
	char *record;
	char data[BUFFER_SIZE];
	//char *ddata = NULL;
	const char delims[2] = ";";
	int count = 0;
	char *tmp1 = NULL;
	char *tmp2 = NULL;
	char *tmp3 = NULL;
	Node *head = NULL;





//	if (argc != 2){
//		printf("Usage of: <file>\n ", argv[0]);
//	}

	stream = fopen("File.csv", "r");
	if(stream == NULL){
		perror("failed to open");
		exit(EXIT_FAILURE);
	}

	while((fgets(data, BUFFER_SIZE, stream))){
		record = strtok(data, delims);
			while(record != NULL){
				//printf("Record number:%d Data:%s ", count++, record);
				tmp3 = tmp2;
				tmp2 = tmp1;
				tmp1 = record;
				if (tmp3 != NULL){
					addVertexToList(&head, tmp3, tmp2, tmp1);
					tmp1 = NULL;
					tmp2 = NULL;
					tmp3 = NULL;
				}
				//sprintf(ddata, "%s", record + sizeof(record));
				//printf(" %s \n", record);
				record = strtok(NULL, delims);
			}


//				while (record != NULL){
//					ddata[i] = *record;
//					i++;
//					//printf(" %s \n", record);
//					record = strtok(NULL, delims);
//				}
//				count++;

	}

	printList(head);


	//printf("\nline count: %d", count);
	fclose(stream);
	exit(EXIT_SUCCESS);

}

