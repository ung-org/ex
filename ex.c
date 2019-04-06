#define _XOPEN_SOURCE 700
#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int visual = 0;
	const char *options = "rRsvc:t:w:";
	if (!strcmp(basename(argv[0]), "vi")) {
		options = "rRc:t:w:";
		visual = 1;
	}

	char *command = NULL;
	int recovery = 0;
	int readonly = 0;
	int batch = 0;
	char *tag = NULL;
	int window = 0;

	int c;
	while ((c = getopt(argc, argv, options)) != -1) {
		switch (c) {
		case 'c':
			command = optarg;
			break;

		case 'r':
			recovery = 1;
			break;

		case 'R':
			readonly = 1;
			break;

		case 's':
			batch = 1;
			break;

		case 't':
			tag = optarg;
			break;

		case 'v':
			visual = 1;
			break;

		case 'w':
			window = atoi(optarg);
			break;

		default:
			return 1;
		}
	}

	printf("starting in %s mode\n", visual ? "visual" : "line");
	printf("tag: %s\n", tag ? tag : "-");
	printf("command: %s\n", command ? command : "-");

	return 0;
}
