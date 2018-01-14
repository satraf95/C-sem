/*
 * DFSMain.h
 *
 *  Created on: 15. 11. 2017
 *      Author: frantisek
 */

#ifndef DFSMAIN_H_
#define DFSMAIN_H_

typedef struct Node {
	double vertex;
	struct Node *next;
} Node;

typedef struct Graph {
	double vertex;
	double value;
	int visited;
	struct Graph *next;
} Graph;

int vertexCount;
Graph **G;
int *visited;

void addEdge(double vertexS, double value, double vertexD, int Vertexcount);
void addVertex(double ver, int vertexCount, int i);

void printList(Graph *head, Graph **G);
char *getValue(char *record);
double *findAllVertices(double record[], int count);
void DFS(double vertexS, double vertexD, int maxPath);

#endif /* DFSMAIN_H_ */
