#include "file.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
// creates a new file
void touch(Directory * *parent, char *command);
// alphabetically orders all the files and subdirectories
void reorder(Directory **parent);
// displays the path to the current directory
void pwd(Directory *dir, int time);
// creates a new directory
void mkdir(Directory **parentDir, char *command);
// lists all items inside a directory
void ls(Directory *folder);
// deletes file system
int delete(Directory **root);
// creates file system
void create(Directory **root);
// changed the current directory
Directory *cd(Directory *current, char *command);
// interprets the command and returns a code
int interpreter(char *command);
// lists items recursively
void tree(Directory *top, int tab_level);
// removes file
void rm(Directory **dir, char *command);
// removes directory
void rmdir(Directory **parent, char *command);
// clear any subdirectory and file after rmdir
void clear_dir(Directory **dir);
// finds file of a certain maximum length, number of chars and content
void find(Directory *dir, int depth, int min, int max, char *content);
