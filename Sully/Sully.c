#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

char* strdup(const char* s);

char* concat(const char* a, const char* b)
{
	char* c = malloc(strlen(a) + strlen(b) + 1);
	strcpy(c, a);
	strcat(c, b);
	return c;
}

int createFile(const char* filename)
{
	FILE* file = fopen(filename, "w");
	FILE* this = fopen(__FILE__, "r");
	if (!file || !this)
		return 0;
	struct stat st;
	stat(__FILE__, &st);
	char* buf = malloc(st.st_size);
	if (!buf)
		return 0;
	fread(buf, st.st_size, 1, this);
	fclose(this);
	fwrite(buf, st.st_size, 1, file);
	fclose(file);
	free(buf);
	return 1;
}

int exec(const char* filename)
{
	if (!createFile(filename))
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
	if (strcmp(__FILE__, "Sully.c")) {
		if (strrchr(__FILE__, '0'))
			return 0;
		char *filename = strdup(__FILE__);
		filename[6] -= 1;
		status = exec(filename);
		free(filename);
	}
	else {
		char* filename = malloc(strlen(__FILE__) + 3);
		strncpy(filename, __FILE__, 5);
		strcat(filename, "_5.c");
		status = exec(filename);
		free(filename);
	}
	return status;
}
