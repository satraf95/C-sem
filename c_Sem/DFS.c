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

void addEdge(char *vertexS, char *vertexD, int count, Graph *G[]) {
	Graph *s, *d, *e, *p;
	int i;

	s = (Graph *) malloc(sizeof(Graph));
	d = (Graph *) malloc(sizeof(Graph));

	strcpy(s->vertex, vertexS);
	s->next = NULL;
	strcpy(d->vertex, vertexD);
	d->next = NULL;

	for (i = 0; i < count; i++) {
		p = G[i];
		if ((p != s) && p == NULL) {
			G[i] = s;
		}
		if (p == s) {
			e = G[i];
			while (e->next != NULL) {
				e = e->next;
			}
			e->next = d;
		}
		break;
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
const char *getField(char *line, int position) {

	const char *record;
	for (record = strtok(line, ";"); record && *record;
			record = strtok(NULL, ";\n")) {
		if (!--position)
			return record;
	}

	return NULL;
}
char *findAllVertices(char *record) {
	char *tmp = malloc(strlen(record));
	char *temp = malloc(strlen(record));
	strcpy(tmp, record);
	//printf("tmp %s\n", tmp);

	int i, j, k = 0;
	int length = strlen(record);
	//printf("length %d \n", length);
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
	//printf("%s ", temp);

	return (temp);

}
void DFS(int i, Graph *G[]) {
	Graph *p;

	p = G[i];
	visited[i] = 1;
	while (p != NULL) {
		i = p->vertex;
		if (!visited[i]) {
			DFS(i, G);
		}
		p = p->next;
	}
}
