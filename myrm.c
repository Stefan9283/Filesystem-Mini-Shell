#include "functions.h"

void rm(Directory **dir, char *command)
{
	//printf("\nrm\n");
	//puts(command);
	char *pch, *name;
pch = strtok(command, " ,.-");
while (pch != NULL) {
	name = pch;
	pch = strtok(NULL, " ,.-");
}

char string[30];

strcpy(string, name);

FileChain *head;

head = (*dir)->files;
FileChain *found;
found = NULL;
int i = 1;

FileChain *prev;

prev = (*dir)->files;

while ((*dir)->files) {

	if (i > 2) {
		if (prev)
			prev = prev->next;
		}
	if (strcmp((*dir)->files->file->name, string) == 0) {
		found = (*dir)->files;
		break;
		}
	i++;
	(*dir)->files = (*dir)->files->next;
}
(*dir)->files = head;

if (found) {


	if (i == 1) {
		(*dir)->files = (*dir)->files->next;
		free(found->file->data);
		free(found->file->name);
		free(found->file);
		free(found);
	} else {
		prev->next = found->next;
		free(found->file->data);
		free(found->file->name);
		free(found->file);
		free(found);

	}


} else {
	printf("Cannot remove \'%s\': No such file!\n", string);
}

}
