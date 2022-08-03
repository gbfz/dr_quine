#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

char* strdup(const char*);

char* concat(const char* a, const char* b)
{
	char* c = malloc(strlen(a) + strlen(b) + 1);
	strcpy(c, a);
	strcat(c, b);
	return c;
}

int createFile(const char* filename)
{
	FILE* kid = fopen(filename, "w");
	FILE* this = fopen(__FILE__, "r");
	if (!kid || !this)
		return 0xBADF1L;
	struct stat st;
	stat(__FILE__, &st);
	char* buf = malloc(st.st_size);
	if (!buf)
		return 0xBADALL;
	fread(buf, st.st_size, 1, this);
	fclose(this);
	fwrite(buf, st.st_size, 1, kid);
	fclose(kid);
	free(buf);
	return 0;
}

int launch(const char* filename)
{
	if (createFile(filename) != 0)
		return 0xDEAD;
	char* cmd0 = concat("clang ", filename);
	char* cmd = concat(cmd0, " -o Sully; ./Sully");
	free(cmd0);
	int status = system(cmd);
	free(cmd);
	return status;
}

int main()
{
	int status;
	if (strcmp(__FILE__, "Sully.c"))
	{
		if (strrchr(__FILE__, '0'))
			return 0;
		char *filename = strdup(__FILE__);
		filename[6] -= 1;
		status = launch(filename);
		free(filename);
	}
	else
	{
		char* filename = calloc(strlen(__FILE__) + 3, 1);
		strncpy(filename, __FILE__, 5);
		strcat(filename, "_5.c");
		status = launch(filename);
		free(filename);
	}
	return status;
}
