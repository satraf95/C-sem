/*
 * DFSMain.h
 *
 *  Created on: 15. 11. 2017
 *      Author: frantisek
 */

#ifndef DFSMAIN_H_
#define DFSMAIN_H_

typedef struct Node{
	char vertex[32];
	char vertex1[32];
	double value;
	struct Node *next;
}Node;

typedef struct Graph {
	char vertex[32];
	struct Graph *next;
}Graph;

//Graph *G[20];
int visited[20];

void addEdge (char *vertexS, char *vertexD, int count, Graph *G[]);

void printList (Node *head);
char *getValue(char *record);
int vertexCount(FILE *stream);
const char *getField(char *line, int num);
char *findAllVertices(char *record);
void DFS (int i, Graph *G[]);


#endif /* DFSMAIN_H_ */
