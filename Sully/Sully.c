#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concat3(const char* a, const char* b, const char* c)
{
	char* d = malloc(strlen(a) + strlen(b) + strlen(c) + 1);
	strcpy(d, a);
	strcat(d, b);
	strcat(d, c);
	return d;
}

int main()
{
	if (strchr(__FILE__, '0'))
		return 0;
	int i = 5;
	char* filename = concat3("Sully_", (char []){i + '0', 0}, ".c");
	FILE* kid = fopen(filename, "w");
	FILE* this = fopen(__FILE__, "r");
	if (!this || !kid)
		return 0xDEAD;
	char* line = NULL;
	size_t n = 0;
	while (getline(&line, &n, this) != -1)
	{
		if (strstr(line, "\tint i ="))
			fprintf(kid, "\tint i = %d;\n", i - 1);
		else
			fprintf(kid, "%s", line);
		free(line);
		line = NULL;
	}
	free(line);
	fclose(kid);
	fclose(this);
	char* cmd = concat3("gcc ", filename, " -o Sully; ./Sully"); 
	system(cmd);
	free(cmd);
	free(filename);
}
