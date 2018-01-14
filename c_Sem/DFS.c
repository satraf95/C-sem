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

void addVertex(double ver, int vertexCount, int i) {
	Graph *v;
	v = (Graph *) malloc(sizeof(Graph));
	//s = (Node *) malloc(sizeof(Node));
	//int i;
//	for (i = 0; i < vertexCount; i++) {
//		printf("ver %d %f\n", i, ver[i]);
//		v->vertex = ver[i];
//		printf("ver v %f\n", v->vertex);
//		v->next = NULL;
//		G[i] = v;
//
//	}
	v->vertex = ver;
	v->next = NULL;

	G[i] = v;

//	for (i = 0; i < vertexCount; i++) {
//		s = G[i];
//		printf("addV %d %f\n", i, s->vertex);
//
//	}
	//free(v);
}

void addEdge(double vertexS, double value, double vertexD, int Vertexcount) {
	Graph *s, *d;
	int i;
	double tmp;

	s = (Graph *) malloc(sizeof(Graph));
	d = (Graph *) malloc(sizeof(Graph));

	d->vertex = vertexD;
	d->value = value;
	d->next = NULL;

	for (i = 0; i < Vertexcount; i++) {
		s = G[i];
		//printf("addEdge vertex %f\n", tmp);
		if (s->vertex == vertexS) {
			while (s->next != NULL) {
				s = s->next;
			}
			s->next = d;
		}
		//G[i] = s;
		//break;
	}
	//free(d);
	//free(s);
}
void printList(Graph *head, Graph **G) {
	int i;
	Graph *p = malloc(sizeof(Graph));
	for (i = 0; i < 10; i++) {
		p = G[i];
		while (p) {
			printf("%s %f\n", p->vertex, p->value);
			p = p->next;
		}
	}
//	while (head) {
//		printf("Vertex:%s %s %f\n", head->vertex, head->value);
//		head = head->next;
//	}
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
double *findAllVertices(double record[], int count) {
	int i, j, k = 0;
	double *tmp = malloc(sizeof(double) * count);

	for (i = 0; i < count; i++) {
		for (j = 0; j < i; j++) {
			if (record[i] == record[j]) {
				break;
			}
		}
		if (i == j) {
			tmp[k] = record[i];
			k++;

		}
	}
	vertexCount = k;

	return tmp;
}
void DFS(double vertexS, double vertexD, int maxPath) {
	Graph *p, *d;
	p = (Graph *) malloc(sizeof(Graph));
	int i;
	double pomVer = vertexS;
	double prePomVer;
	printf("start %f finish %f \n", vertexS, vertexD);
	while (vertexD != pomVer) {
	printf("vertext %f \n", pomVer);
	for (i = 0; i < vertexCount; i++) {
		p = G[i];
		if (p->vertex == pomVer) {
			//prePomVer = p->vertex;
			printf("if %f\n", pomVer);
			if (p->next == NULL){
				p->visited = 1;
				//pomVer = vertexS;
				break;
			}
			p = p->next;
			while (p->visited == 1) {
				p = p->next;
			}
			printf("po while %f \n", p->vertex);
			p->visited = 1;

			pomVer = p->vertex;
		}

		}
	}

	//	p = G[i];
//	visited[i] = 1;
//	while (p != NULL) {
//		i = p->vertex;
//		if (!visited[i]) {
//			DFS(i, G);
//		}
//		p = p->next;
//	}
}
