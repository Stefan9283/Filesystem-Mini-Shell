#include "functions.h"

int interpreter(char *command)
{

if (strstr(command, "find "))
	return 9;
else if (strstr(command, "rmdir "))
	return 8;
else if (strstr(command, "tree"))
	return 7;
else if (strstr(command, "rm "))
	return 6;
else if (strstr(command, "cd "))
	return 5;
else if (strstr(command, "pwd"))
	return 4;
else if (strstr(command, "ls"))
	return 3;
else if (strstr(command, "mkdir "))
	return 2;
else if (strstr(command, "touch "))
	return 1;
else if (strstr(command, "delete fs"))
	return -1;
else if (strstr(command, "create fs"))
	return 0;
return 404;
}
