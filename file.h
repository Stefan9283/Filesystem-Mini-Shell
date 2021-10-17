#ifndef __FILE_H__
#define __FILE_H__



typedef struct Directory {
// The name of the directory
char *name;
// TODO: The list of files of the current directory
struct FolderChain *folders;
// TODO: The list of directories of the current directory
struct FileChain *files;
// The parent directory of the current directory (NULL for the root directory)
struct Directory *parentDir;
} Directory;

typedef struct File {
// The name of the file
char *name;
// The size of the file
int size;
// The content of the file
char *data;
// The directory in which the file is located
Directory *dir;
} File;


typedef struct FolderChain {
Directory *dir;
struct FolderChain *next;
} FolderChain;


typedef struct FileChain {
File *file;
struct FileChain *next;
} FileChain;



#endif /* __FILE_H__ */
