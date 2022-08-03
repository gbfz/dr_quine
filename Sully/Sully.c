#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

char* strdup(const char* s);

char* strjoin(const char* a, const char* b)
{
	char *result = malloc(strlen(a) + strlen(b) + 1);
	strcpy(result, a);
	strcat(result, b);
	return result;
}

size_t getFilesize()
{
	struct stat st;
	stat(__FILE__, &st);
	return st.st_size;
}

int main()
{
	FILE* thisFile = fopen(__FILE__, "r");
	size_t size = getFilesize();
	char* buf = malloc(size);
	fread(buf, size, 1, thisFile);
	fclose(thisFile);
	char* filename = strdup(__FILE__);
	char* suffix = strrchr(filename, '_');
	if (suffix) {
		if (*(suffix + 1) == 0) {
			free(buf);
			free(filename);
			return 0;
		}
		*(suffix + 1) -= 1;
	}
	else {
		free(filename);
		filename = malloc(strlen(__FILE__) + 3);
		strncpy(filename, __FILE__, 5);
		strcat(filename, "_5.c");
	}
	FILE* kid = fopen(filename, "w");
	fwrite(buf, size, 1, kid);
	fclose(kid);
	free(buf);

	char* cmd_0 = strjoin("clang ", filename);
	char* cmd = strjoin(cmd_0, "; ./a.out");
	free(cmd_0);
	system(cmd);

	free(filename);
}
