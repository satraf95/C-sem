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
	char *tmpRecord;
	char line[BUFFER_SIZE];
	double tmpValue;
	const char *delims = ";";
	char* tmp;
	int i = 0, j = 1;

	char *tmp1 = malloc(sizeof(char) * 100);
	char *tmp2 = malloc(sizeof(char) * 100);
	//char *tmp3 = malloc(sizeof(char) * 100);
	;
	Node *head = NULL;

//	if (argc < 4) {
//		printf("Missing one or more parameter\n");
//		return MISSING_PARAMETER;
//	}

	stream = fopen("File.csv", "r");
	if (stream == NULL) {
		printf("failed to open\n");
		return FAILED_TO_OPEN;
	}



	//while (j < 3) {

		while ((fgets(line, BUFFER_SIZE, stream))) {
	getField(line, 2, stream, tmp1);
//
//			tmp = strdup(line);
//			printf("Field %d would be %s \n", 0, getField(tmp, 2));
//			strcpy(tmp1 + i, tmp);
//			i++;

//		record = strtok(line, delims);
//		while (record != NULL) {
//			tmpRecord = malloc(sizeof(record));
//			strcpy(tmpRecord, getValue(record));
//			tmp3 = tmp2;
//			tmp2 = tmp1;
//			tmp1 = tmpRecord;
//			if (tmp3 != NULL) {
//				tmpValue = strtod(tmp1, &tmp1);
//				addVertexToList(&head, tmp3, tmp2, tmpValue);
//				tmp1 = NULL;
//				tmp2 = NULL;
//				tmp3 = NULL;
//			}
//			record = strtok(NULL, delims);
//		}
//		free(tmpRecord);

		}
		//j++;
	//}

	//printf("j %d \n", j);
	printf("%s\n", tmp1);
	//tmp3 = findAllVertexs(tmp1);
	//strcpy(tmp2, findAllVertexs(tmp1));
	//printf("%s\n", tmp2);


	//printList(head);

	fclose(stream);
	free(tmp);
	free(tmp1);
	free(tmp2);
	exit(EXIT_SUCCESS);

}

