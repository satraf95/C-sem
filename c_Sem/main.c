/*
 * main.c
 *
 *  Created on: 24. 10. 2017
 *      Author: frantisek
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]){
	FILE *stream;
	char *line = NULL;
	char *record;
	ssize_t len = 0;
	ssize_t nread;
	int count = 0;

	if (argc != 4){
		printf("Usage of: <file>\n ", argv[0]);
	}

	stream = fopen(argv[1], "r");
	if(stream == NULL){
		perror("failed to open");
		exit(EXIT_FAILURE);
	}
	while((nread = getline(&line, &len, stream)) != -1){
		count++;
		//record = strtok(nread, ';');
		printf("Retrieved line of length %zu:\n", nread);
		fwrite(line, nread, 1, stdout);

	}
	printf("\nline count: %d", count);
	free(line);
	fclose(stream);
	exit(EXIT_SUCCESS);

}

