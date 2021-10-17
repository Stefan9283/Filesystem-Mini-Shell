#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// my header files
#include "file.h"
#include "functions.h"

int main(void)
{
int programshouldntclose = 1;
char *command;
command = (char *)malloc(201*sizeof(char));

Directory *root;
int choice;
int thereisnofs = 1;
Directory *current;

while (programshouldntclose) {
	fgets(command, 200, stdin);
	command[strlen(command)-1] = '\0';
	choice = interpreter(command);

	//puts(command);


	if (choice == 1)
		touch(&current, command+6);
	else
		if (choice == 0) {
			create(&root);
			current = root;
			thereisnofs = 0;
		}
	if (!thereisnofs) {
		if (choice == -1)
			programshouldntclose = delete(&root);
		if (choice == 3) {
			ls(current);
			printf("\n");
		}
		if (choice == 2)
			mkdir(&current, command+6);

		if (choice == 4) {
			pwd(current, 0);
			printf("\n");
		}
		if (choice == 5)
			current = cd(current, command+3);
		if (choice == 7) {

			if (current->parentDir)
				printf("/%s\n", current->name);
			else
				printf("/\n");
			tree(current, 1);
		}
		if (choice == 6)
			rm(&current, command+3);
		if (choice == 8)
			rmdir(&current, command+6);
		if (choice == 9) {
			char *pch, *content;

			int depth, min, max, index = 1;

			content = NULL;


			pch = strtok(command, " ,-");
			while (pch != NULL) {
				if (index == 2)
					depth = atoi(pch);

				if (index == 3)
					min = atoi(pch);

				if (index == 4)
					max = atoi(pch);

				if (index == 5)
					content = pch;

				index++;
				pch = strtok(NULL, " ,-");
				}
			find(current, depth, min, max, content);
			printf("\n");
			//printf("%d %d %d %s\n",depth,min,max,content);

		}

	}
}

free(command);
return 0;
}
