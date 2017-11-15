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

void addVertexToList(Node **head, char *vertex, char *vertex1, char *value) {

	Node *v, *temp;

	temp = malloc(sizeof(Node));
	strcpy(temp->vertex, vertex);
	strcpy(temp->vertex1, vertex1);
	strcpy(temp->value, value);
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
		printf("Vertex:%s %s %s\n", head->vertex, head->vertex1, head->value);
		head = head->next;
	}
}
char *getValue(char *record) {
	int strLength = strlen(record);
	int i;
	int tmp;
	for (i = 0; i < strLength; i++) {
		tmp = record[i];
		if (tmp == 0) {
			break;
		}
		if (tmp < 48 || tmp > 57) {
			memmove(&record[i], &record[i + 1], strlen(record) - i);
			i--;
		}
	}
	return record;
}

