#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *read_long_line(FILE *file);

int main(int argc, char *argv[])
{
	char *prev_line, *curr_line;
	curr_line = (char*) malloc(2048 * sizeof(char));
	prev_line = (char*) malloc(2048 * sizeof(char));
	curr_line = (char*) read_long_line(stdin);
	while(curr_line != NULL)
	{
		if(strcmp(curr_line, prev_line) == -10)
		{
			break;
		}
		else if(!strcmp(curr_line, prev_line))
			/*Do nothing since duplicant adjacent lines*/;
		else
			fputs(curr_line, stdout);
		strcpy(prev_line, curr_line);
		curr_line = (char*)read_long_line(stdin);
	}
	free(prev_line);
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
