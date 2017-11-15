/*
 * main.c
 *
 *  Created on: 24. 10. 2017
 *      Author: frantisek
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "DFS.h"

#define BUFFER_SIZE 1024
#define MISSING_PARAMETER 1
#define FAILED_TO_OPEN 2

int main(int argc, char *argv[]) {
	FILE *stream;
	char *record;
	char data[BUFFER_SIZE];
	const char *delims = ";";

	char *tmp1 = NULL;
	char *tmp2 = NULL;
	char *tmp3 = NULL;
	Node *head = NULL;

	if (argc < 4) {
		printf("Missing one or more parameter");
		return MISSING_PARAMETER;
	}

	stream = fopen("File.csv", "r");
	if (stream == NULL) {
		printf("failed to open");
		return FAILED_TO_OPEN;
	}

	while ((fgets(data, BUFFER_SIZE, stream))) {
		record = strtok(data, delims);
		while (record != NULL) {
			strcpy(record, getValue(record));

			tmp3 = tmp2;
			tmp2 = tmp1;
			tmp1 = record;
			if (tmp3 != NULL) {
				addVertexToList(&head, tmp3, tmp2, tmp1);
				tmp1 = NULL;
				tmp2 = NULL;
				tmp3 = NULL;
			}

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

