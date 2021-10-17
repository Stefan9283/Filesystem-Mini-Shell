#include "functions.h"

void clear_dir(Directory **dir)
{
if (*dir != NULL) {



	while ((*dir)->files) { //pentru fisiere

		FileChain *prev;

		prev = (*dir)->files;
		(*dir)->files = (*dir)->files->next;

		free(prev->file->data);
		free(prev->file->name);
		free(prev->file);

		free(prev);

		}



	while ((*dir)->folders) { //pentru directoare
		//apelez recursiv
		clear_dir(&(*dir)->folders->dir);
		//sterg pointerii de fisiere si directoare apoi numele
		FolderChain *prev;

		prev = (*dir)->folders;
		(*dir)->folders = (*dir)->folders->next;
		//printf("free folder %s\n",prev->dir->name);
		free(prev);

		}


		free((*dir)->files);
		free((*dir)->folders);
		free((*dir)->name);
		free(*dir);

	}




}

void rmdir(Directory **dir, char *command)
{
		//printf("\n\nRMDIR\n");
		//puts(command);

		char *pch, *name;

		pch = strtok(command, " ,.-");
		while (pch != NULL) {
			name = pch;
			pch = strtok(NULL, " ,.-");
		}

		//puts(name);


	char string[30];

	strcpy(string, name);

	FolderChain *head;

	head = (*dir)->folders;
	FolderChain *found;

	found = NULL;
	int i = 1;

	FolderChain *prev;

	prev = (*dir)->folders;

	while ((*dir)->folders) {

		if (i > 2) {
			if (prev)
				prev = prev->next;
			}
		if (strcmp((*dir)->folders->dir->name, string) == 0) {
			//printf("exista\n");
			found = (*dir)->folders;
			break;
			}
		//printf("%d\n",i);
		i++;
		(*dir)->folders = (*dir)->folders->next;
	}
	(*dir)->folders = head;

	if (found) {
			//printf("index %d\n",i);
			//printf("prev  ");
		//puts(prev->file->name);
			//printf("found ");
		//puts(found->file->name);

		if (i == 1) {
			(*dir)->folders = (*dir)->folders->next;
			clear_dir(&found->dir);
			free(found);
		} else {
			prev->next = found->next;
			clear_dir(&found->dir);
			free(found);

		}


	} else {
		printf("Cannot remove \'%s\': No such directory!\n", string);
	}



}
