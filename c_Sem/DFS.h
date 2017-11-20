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
	double value;
	struct Graph *next;
}Graph;

void addVertexToList (Node **head, char *vertexS, char *vertexD, double value);

void printList (Node *head);
char *getValue(char *record);
int vertexCount(FILE *stream);
char *getField(char *line, int num);
char *findAllVertexs(char *record);


#endif /* DFSMAIN_H_ */
