#include <stdio.h>

#define WRAP(s) QUOTE(s)
#define QUOTE(s) #s
#define EXEC(x) int main() { FILE* kid = fopen("./Grace_kid.c", "w"); fputs("#include <stdio.h>\n\n#define WRAP(s) QUOTE(s)\n#define QUOTE(s) #s\n#define EXEC(x) "x"\n\nEXEC(WRAP(EXEC(x)))", kid); fputc('\n', kid); fclose(kid); }

EXEC(WRAP(EXEC(x)))
