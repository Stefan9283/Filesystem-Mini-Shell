#include "functions.h"

void pwd(Directory *dir, int time)
{

if (dir->parentDir) {
	pwd(dir->parentDir, time+1);
	printf("/%s", dir->name);
} else if (!time)
	printf("/");
}
