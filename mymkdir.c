#include "functions.h"


void mkdir(Directory **parentDir, char *command)
{
char *pch, *name;
name = NULL;

pch  =  strtok(command, " ");
while (pch !=  NULL) {
	name = pch;
	pch  =  strtok(NULL, " ");
}

if (name) {
	// atribuirea atributelor noii instante
	Directory *d;

	d = (Directory *)malloc(sizeof(Directory));
	d->name = (char *)malloc(20*sizeof(char));
	strcpy(d->name, name);



	// verific daca mai exista numele
	int wontskip = 1;

	FolderChain *dirhead;

	dirhead = (*parentDir)->folders;
	while ((*parentDir)->folders) {
		if (strcmp(d->name, (*parentDir)->folders->dir->name) == 0) {
			wontskip--;
			(*parentDir)->folders = dirhead;
			break;
			}
		(*parentDir)->folders = (*parentDir)->folders->next;
		}


	(*parentDir)->folders = dirhead;


	if (wontskip) {
		d->files = NULL;
		d->folders = NULL;
		d->parentDir = *parentDir;

		// atasarea noului fisier in lista de fisiere a parintelui
		FolderChain *fc;

		fc = (FolderChain *)malloc(sizeof(FolderChain));
		fc->dir = d;

		if (!((*parentDir)->folders)) {

			fc->next = NULL;
			(*parentDir)->folders = fc;

		} else {
			FolderChain *head;

			head = (*parentDir)->folders;

			FolderChain *tmp;

			tmp = (*parentDir)->folders;
			while (tmp->next)
				tmp = tmp->next;

			fc->next = NULL;

			tmp->next = fc;
			tmp = head;
		}

	} else {
		free(d->name);
		free(d);
		}
}
}
