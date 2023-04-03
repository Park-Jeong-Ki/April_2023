#include <stdio.h>
#include <string.h>

int find_max_len(char* str) {
	int max_len = 0;
	char* token = strtok(str, " ");
	while (token != NULL) {
		int len = strlen(token);
		max_len = (len > max_len ? len : max_len);
		token = strtok(NULL, " ");
	}
	return max_len;
}

void print_top_bottom(int width) {
    for (int i = 0; i < width; i++) {
        printf("*");
    }
    printf("\n");
}

void do_print(char* str) {
    int max_len = find_max_len(strdup(str));
    int top_bottom_width = max_len + 4;
    int i, j;

	print_top_bottom(top_bottom_width);

    char* token = strtok(str, " ");
    while (token != NULL) {
        printf("* %s", token);
		int len = strlen(token);
		for (; len < max_len; len++) {
			printf(" ");
		}
        printf(" *\n");
        token = strtok(NULL, " ");
    }

	print_top_bottom(top_bottom_width);
}

int main(int argc, char** argv) {
    if (argc < 2)
		return 1;
	for (int i=1; i < argc; i++) {
		do_print(argv[i]);
	}
}
