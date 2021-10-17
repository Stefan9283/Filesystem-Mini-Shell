#include "functions.h"

void find(Directory *dir, int depth, int min, int max, char *content)
{
	if (depth > -1) {

		FileChain *headf;

		headf = dir->files;

		while (dir->files) {

			if (strstr(dir->files->file->data, content)) {
				File *f;

				f = dir->files->file;
				if (f->size <= max && f->size >= min)
					printf("%s ", dir->files->file->name);
				}
				dir->files = dir->files->next;
			}
		dir->files = headf;

		FolderChain *headd;

		headd = dir->folders;

		while (dir->folders) {

			find(dir->folders->dir, depth-1, min, max, content);
			dir->folders = dir->folders->next;
		}

		dir->folders = headd;
	}
}
