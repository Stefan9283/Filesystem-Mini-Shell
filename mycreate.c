#include "functions.h"

void create(Directory **root)
{
*root = (Directory *)malloc(sizeof(Directory));
(*root)->files = NULL;
(*root)->folders = NULL;
(*root)->parentDir = NULL;
(*root)->name = (char *)malloc(sizeof(char)*30);
strcpy((*root)->name, "root");
}
