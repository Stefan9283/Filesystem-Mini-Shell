#include "functions.h"


void ls(Directory  *folder)
{
FileChain  *headf;
FolderChain  *headd;
headf = folder->files;
headd = folder->folders;
reorder(&folder);
if (folder->files) {

	while (folder->files) {

		printf("%s ", folder->files->file->name);
		folder->files = folder->files->next;
		}
	folder->files = headf;
}
if (folder->folders) {

	while (folder->folders) {

		printf("%s ", folder->folders->dir->name);
		folder->folders = folder->folders->next;
	}

	folder->folders = headd;
}

}
