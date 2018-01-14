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
	//Graph **G;
	double *allVertices;
	double *all;
	double firstColumn[10];
	double secondColumn[10];
	double thirdColumn[10];
	char *record;
	char *tmpRecord;
	char line[BUFFER_SIZE];
	double tmpValue;
	char* tmp, *p;
	int i, j, k, q, count = 0, lengthF, lengthS, lengthA, size1 = 0, size2 = 0;

	tmp = malloc(sizeof(char) * 100);
	all = malloc(sizeof(double) * 20);
	//allVertices = malloc(sizeof(char) * 100);
	//firstColumn = malloc(sizeof(char) * 100);
	//secondColumn = malloc(sizeof(char) * 100);
	//thirdColumn = malloc(sizeof(char) * 1000);

	Graph *head = NULL;

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
		while ((fgets(line, BUFFER_SIZE, stream))) {
			p = strdup(line);
			strcpy(tmp, getField(p, j));
			switch (j) {
			case 1:
				tmp = getValue(tmp);
				tmpValue = atof(tmp);
				firstColumn[i] = tmpValue;
				i++;
				break;
			case 2:
				tmp = getValue(tmp);
				tmpValue = atof(tmp);
				secondColumn[i] = tmpValue;
				i++;
				break;
			case 3:
				tmp = getValue(tmp);
				tmpValue = atof(tmp);
				thirdColumn[i] = tmpValue;
				i++;
				break;
			}
		}
		fclose(stream);
	}

	lengthF = sizeof(firstColumn) / sizeof(double);
	lengthS = sizeof(secondColumn) / sizeof(double);
	allVertices = malloc(sizeof(double) * (lengthF + lengthS));
	for (q = 0; q < (lengthF + lengthS); q++) {
		if (q < lengthF) {
			allVertices[q] = firstColumn[q];
		} else {
			allVertices[q] = secondColumn[q - lengthF];
		}
	}

	memcpy(all, findAllVertices(allVertices, lengthF + lengthS),
			lengthF + lengthS * sizeof(double));
	all = realloc(all, sizeof(double) * vertexCount);

	G = (Graph **) malloc(sizeof(Graph) * vertexCount);
	visited = malloc(sizeof(int) * vertexCount);

	for (k = 0; k < vertexCount; k++) {
		addVertex(all[k], vertexCount, k);
	}

	for (k = 0; k < lengthF; k++) {
		addEdge(firstColumn[k], thirdColumn[k], secondColumn[k], vertexCount);
		addEdge(secondColumn[k], thirdColumn[k], firstColumn[k], vertexCount);
	}

	DFS(1, 3, 3);

	for (k = 0; k < vertexCount; k++) {
		Graph *p;
		p = G[k];
		printf("jsem zde %f %f\n", p->vertex, p->value);
		while (p->next != NULL) {
			p = p->next;
			printf("pokus %f %f\n", p->vertex, p->value);
		}
	}

	//printList(head);

	//free(firstColumn);
	//free(secondColumn);
	//free(thirdColumn);
	free(tmp);
	//free(tmp1);
	//free(tmp2);
	exit(EXIT_SUCCESS);

}

