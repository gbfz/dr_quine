#include <stdio.h>

/*
   I know this is horrible, but only god can judge me
*/

void print_n(char** src, int start, int end) {
	for (int i = start; i < end; ++i)
		puts(src[i]);
}

void print_n_wrapped(char** src, int start, int end) {
	for (int i = start; i < end; ++i) {
		fputs((char[]){9,9,34,0}, stdout);
		fputs(src[i], stdout);
		puts((char[]){34,44,0});
	}
}

int main() {
	/*
	   Here goes the shitshow...
	*/
	char* src[] = {
		"#include <stdio.h>",
		"",
		"/*",
		"   I know this is horrible, but only god can judge me",
		"*/",
		"",
		"void print_n(char** src, int start, int end) {",
		"	for (int i = start; i < end; ++i)",
		"		puts(src[i]);",
		"}",
		"",
		"void print_n_wrapped(char** src, int start, int end) {",
		"	for (int i = start; i < end; ++i) {",
		"		fputs((char[]){9,9,34,0}, stdout);",
		"		fputs(src[i], stdout);",
		"		puts((char[]){34,44,0});",
		"	}",
		"}",
		"",
		"int main() {",
		"	/*",
		"	   Here goes the shitshow...",
		"	*/",
		"	char* src[] = {",
		"	};",
		"	print_n(src, 0, 24);",
		"	print_n_wrapped(src, 0, 29);",
		"	print_n(src, 24, 29);",
		"}",
	};
	print_n(src, 0, 24);
	print_n_wrapped(src, 0, 29);
	print_n(src, 24, 29);
}
