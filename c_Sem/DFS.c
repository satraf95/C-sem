/*
 * DFS.c
 *
 *  Created on: 15. 11. 2017
 *      Author: frantisek
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DFS.h"

void addVertexToList(Node **head, char *vertexS, char *vertexD, double value) {

	Node *v, *temp;

	temp = malloc(sizeof(Node));
	strcpy(temp->vertex, vertexS);
	strcpy(temp->vertex1, vertexD);
	temp->value = value;
	temp->next = NULL;

	if (*head) {
		v = *head;
		while (v->next) {
			v = v->next;
		}
		v->next = temp;
	} else {
		*head = temp;
	}

}

void printList(Node *head) {
	while (head) {
		printf("Vertex:%s %s %f\n", head->vertex, head->vertex1, head->value);
		head = head->next;
	}
}
char *getValue(char *record) {
	int strLength = strlen(record);
	char *array = malloc(strLength);
	strcpy(array, record);
	int i;
	int tmp;
	for (i = 0; i < strLength; i++) {
		tmp = array[i];
		if (tmp == 0) {
			break;
		}
		if (tmp < 48 || tmp > 57) {
			memmove(&array[i], &array[i + 1], strlen(array) - i);
			i--;
		}
	}
	return (array);

}

char *getField(char *line, int position,FILE *stream, char *output) {
	int count = 0;
	char *tmp;
	int i = 0;
	output = malloc(sizeof(line));
	while (fgets(line, sizeof(line), stream)) {
		tmp = strtok(line, ";");
		while (tmp != NULL) {
			count++;
			if (count == position) {
				strcpy(output + i, tmp);
				i++;
			}
			tmp = strtok(NULL, ";");
		}
		i = 0;
	}

//	char *record;
//	char *delims = ";";
//	for (record = strtok(line, delims); record && *record;
//			record = strtok(NULL, ":\n")) {
//		if (!--position) {
//			return record;
//		}
//	}

	return output;
}
char *findAllVertexs(char *record) {
	char *tmp = malloc(strlen(record));
	char *temp = malloc(strlen(record));
	strcpy(tmp, record);
	printf("tmp %s\n", tmp);

	int i, j, k = 0;
	int length = strlen(record);
	printf("length %d \n", length);
	for (i = 0; i < length; i++) {
		for (j = 0; j < i; j++) {
			if (tmp[i] == tmp[j]) {
				break;
			}
		}
		if (i == j) {

			printf("unique %d %d \n", i, tmp[i]);

			temp[k] = tmp[i];
			k++;
		}
	}
	free(tmp);
	//printf("%s ", temp);

	return (temp);
	free(temp);
}

