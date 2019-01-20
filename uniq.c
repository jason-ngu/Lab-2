#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *read_long_line(FILE *file);

int main(int argc, char *argv[])
{
	char *curr_line, *next_line;
	int x;
	curr_line = (char*) malloc(2048 * sizeof(char));
	curr_line = (char*)read_long_line(stdin);
	next_line = (char*) malloc(2048 * sizeof(char));
	next_line = (char*)read_long_line(stdin);
	while(next_line != NULL)
	{
		x = strcmp(curr_line, next_line);
		if (x == -10)
			break;
		else if(!x)
			/*Do nothing since duplicant adjacent lines*/;
		else
			fputs(curr_line, stdout);
		strcpy(curr_line, next_line);
		next_line = read_long_line(stdin);
	}
	if(!x || x == -10)
		/*Do nothing since duplicant adjacent lines*/;
	else
		fputs(curr_line, stdout);
	free(curr_line);
	free(next_line);
	return 0;
}

char *read_long_line(FILE *file)
{
	int max = 2048;
	char *line = (char*) malloc(max * sizeof(char));
	line = fgets(line, max, file);
	if(line == NULL)
	{
		return NULL;
	}
	else if (strlen(line) > max)
	{
		max = max * 2;
		line = realloc(line, max);
	}
	free(line);
	return line;
}
