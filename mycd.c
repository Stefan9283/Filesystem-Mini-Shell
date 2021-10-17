#include "functions.h"

Directory *cd(Directory *current, char *command)
{

char *pch, *name;

name = NULL;

pch = strtok(command, " ,-");
while (pch != NULL) {
	name = pch;
	pch = strtok(NULL, " ,-");
}

if (name) {
	char str[30];

	strcpy(str, name);

	if (strcmp(name, "..") == 0) {
		if (strcmp(current->name, "root") == 0)
			return current;
		else
			return current->parentDir;
	} else {


		FolderChain *tmp;

		tmp = current->folders;
		while (tmp) {
			if (strcmp(tmp->dir->name, str)  ==  0)
				return tmp->dir;

			tmp = tmp->next;
		}

		printf("Cannot move to '%s': No such directory!\n", name);
		return current;

	}
}

return current;

}
