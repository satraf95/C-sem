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
	char value[64];
	struct Node *next;
}Node;

void addVertexToList (Node **head, char *vertex, char *vertex1, char *value);
void printList (Node *head);
void deleteChars (char *string, char delims);


#endif /* DFSMAIN_H_ */
