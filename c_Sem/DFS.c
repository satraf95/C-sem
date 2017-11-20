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
int vertexCount(FILE *stream) {

	return NULL;
}
char *getField(char *line, int num) {
	char *record;
	for (record = strtok(line, ';'); record && *record;
			record = strtok(NULL, ":\n")) {
		if (!--num) {
			return record;
		}
	}

	return NULL;
}
char *findAllVertexs(char *record) {
	char *tmp = malloc(strlen(record));
	int i, j;
	int length = strlen(record);
	char *tmpVal = malloc(sizeof(char));
	for (i = 0; i < length; i++) {
		strcpy(tmpVal, record[i]);
		for (j = 0; j < length; j++) {
			if (tmpVal[j] == record[i]) {
				strcpy(tmpVal, tmp[i]);
			}
		}
	}

	return (tmp);
}

