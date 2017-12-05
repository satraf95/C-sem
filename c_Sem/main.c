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
	Graph *G;
	char *allVertices;
	char *firstColumn;
	char *secondColumn;
	char *thirdColumn;
	char *record;
	char *tmpRecord;
	char line[BUFFER_SIZE];
	double tmpValue;
	char* tmp, *tmp1, *tmp2, *p;
	int i, j, k, count = 0;

	tmp = malloc(sizeof(char) * 100);
	tmp1 = malloc(sizeof(char) * 100);
	firstColumn = malloc(sizeof(char) * 100);
	secondColumn = malloc(sizeof(char) * 100);
	thirdColumn = malloc(sizeof(char) * 1000);

	Node *head = NULL;

//	if (argc < 4) {
//		printf("Missing one or more parameter\n");
//		return MISSING_PARAMETER;
//	}

//	stream = fopen("File.csv", "r");
//	if (stream == NULL) {
//		printf("failed to open\n");
//		return FAILED_TO_OPEN;
//	}



	for (j = 1; j < 4; j++) {
		stream = fopen("File.csv", "r");
		i = 0;
		//memset(tmp, 0, BUFFER_SIZE);
		printf("j = %d\n", j);
		while ((fgets(line, BUFFER_SIZE, stream))) {
			p = strdup(line);
			printf("Field %d would be %s \n", j, (strcpy(tmp, getField(p, j))));
			switch (j) {
			case 1:
				//printf("line = %s\n", line);
				//tmp = strdup(line);
				//getField(tmp, j);
				strcpy(firstColumn + i, tmp);
				i++;
				//printf("case 1 i = %d tmp = %s \n", i, tmp);
				break;
			case 2:
				//printf("line = %s\n", line);
				//tmp1 = strdup(line);
				//getField(tmp1, j);
				strcpy(secondColumn + i, tmp);
				i++;
				//printf("case 2 i = %d tmp1 = %s \n", i, tmp1);
				break;
			case 3:
				//printf("line = %s\n", line);
				//tmp2 = strdup(line);
				//getField(tmp2, j);
				strcpy(thirdColumn + i, tmp);
				i += 10;
				//printf("case 3 i = %d tmp2 = %s \n", i, tmp2);
				break;
			}
		}
		fclose(stream);
	}

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

//j++;
//}
	printf("1 sloupec %s \n", firstColumn);
	printf("2 sloupec %s \n", secondColumn);
	printf("3 sloupec %s \n", thirdColumn);

//	for (k = 0; k < strlen(thirdColumn); k++){
//		//count++;
//		//strcpy(tmp1, (char *)thirdColumn[k]);
//		printf("array[%d] = %d \n", k, thirdColumn[k]);
//	}

	//printf("j %d \n", j);
	//printf("tm1 %s \n", tmp1);
	//tmp2 = findAllVertexs(tmp1);
	//printf("tm2 %s \n", tmp2);
	//strcpy(tmp2, findAllVertexs(tmp1));
	//printf("%s\n", tmp2);

	//printList(head);


	free(firstColumn);
	free(secondColumn);
	free(thirdColumn);
	//free(tmp);
	//free(tmp1);
	//free(tmp2);
	exit(EXIT_SUCCESS);

}

