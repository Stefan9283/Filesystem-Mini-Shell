#include "functions.h"

void tree(Directory *top, int tab_level)
{
int i;
reorder(&top);
if (top != NULL) {
	FileChain *head1;

	head1 = top->files;
	while (top->files) {
		for (i = 0; i < tab_level; i++)
			printf("    ");
		printf("%s\n", top->files->file->name);
		top->files = top->files->next;
	}
	top->files = head1;

	FolderChain *head2;

	head2 = top->folders;
	while (top->folders) {
		for (i = 0; i < tab_level; i++)
			printf("    ");
		printf("%s\n", top->folders->dir->name);
		tree(top->folders->dir, tab_level+1);
		top->folders = top->folders->next;
	}
	top->folders = head2;
}
}
