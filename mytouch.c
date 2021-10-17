#include "functions.h"

void touch(Directory **parent, char *command)
{
// citirea atributelor
char *name, *content;

content = NULL;
char *pch;

int mode = 1;
pch = strtok(command, " ");
while (pch != NULL) {
	if (mode) {
		name = pch;
		mode--;
	} else
		content = pch;
	pch = strtok(NULL, " ");
}

// atribuirea atributelor noii instante

if (!content) {
	content = alloca(1);
	content[0] = '\0';
}

{
	File *f;

	f = (File *)malloc(sizeof(File));
	f->name = (char *)malloc((strlen(name)+1)*sizeof(char));
	f->data = (char *)malloc((strlen(content)+1)*sizeof(char));
	strcpy(f->name, name);
	strcpy(f->data, content);
	int datalength = strlen(f->data);

	f->size = datalength;

	// verific daca mai exista numele
	int wontskip = 1;

	FileChain *fileshead;

	fileshead = (*parent)->files;
	while ((*parent)->files) {
		if (strcmp(f->name, (*parent)->files->file->name) == 0) {
			wontskip--;
			(*parent)->files = fileshead;
			break;
			}
		(*parent)->files = (*parent)->files->next;
		}


	(*parent)->files = fileshead;


	// atasarea noului fisier in lista de fisiere a parintelui
	if (wontskip) {
		FileChain *fc;

		fc = (FileChain *)malloc(sizeof(FileChain));
		fc->file = f;

		if (!((*parent)->files)) { // daca director gol

			fc->next = NULL;
			(*parent)->files = fc;

		} else { // daca directorul contine ceva
			FileChain *head;

			head = (*parent)->files;
			while ((*parent)->files->next)
				(*parent)->files = (*parent)->files->next;

			fc->next = NULL;
			(*parent)->files->next = fc;
			(*parent)->files = head;

	}
	} else { // daca s-a mai gasit numele fisierului se face skip
		free(f->name);
		free(f->data);
		free(f);
	}
}
}
void reorder(Directory **folder)
{
FileChain *headf;

FolderChain *headd;

headf = (*folder)->files;
headd = (*folder)->folders;
int shouldntrepeat = 1;

if ((*folder)->files) {
	while ((*folder)->files->next) {
		char string1[30], string2[30];

		strcpy(string1, (*folder)->files->file->name);
		strcpy(string2, (*folder)->files->next->file->name);

		if (strcmp(string1, string2) > 0) {
			shouldntrepeat = 0;
			File *f;

			f = (*folder)->files->file;
			(*folder)->files->file = (*folder)->files->next->file;
			(*folder)->files->next->file = f;
		}

		(*folder)->files = (*folder)->files->next;
	}

	(*folder)->files = headf;
}

if ((*folder)->folders) {
	while ((*folder)->folders->next) {

		char string3[30], string4[30];

		strcpy(string3, (*folder)->folders->dir->name);
		strcpy(string4, (*folder)->folders->next->dir->name);
		if (strcmp(string3, string4) > 0) {
			shouldntrepeat = 0;
			Directory *d;

			d = (*folder)->folders->dir;

			(*folder)->folders->dir = (*folder)->folders->next->dir;
			(*folder)->folders->next->dir = d;
		}

		(*folder)->folders = (*folder)->folders->next;
	}

	(*folder)->folders = headd;
}

if (!shouldntrepeat)
	reorder(folder);


}
