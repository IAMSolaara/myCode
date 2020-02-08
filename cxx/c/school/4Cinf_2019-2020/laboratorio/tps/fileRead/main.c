#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int searchInString(const char str[], const char delim);

int main(int argv, char **argc)
{
	if (argv < 2 || argv > 2)
		printf("Please supply no more than one parameter.");
	else
	{
		char *seps;
		FILE *f = fopen(argc[1], "r");
		char c[1000];

		int lns = 0;
		while (fgets(c, 1000, f) != NULL)
		{
			//declare buffer var array
			char titolo[1000];
			char autore[1000];

			//zerofill buffer
			memset(titolo, 0, sizeof(titolo));
			memset(autore, 0, sizeof(autore));

			//search for first pointer
			char *p = strstr(c, ";");

			int sepPos = (p - c) + 1;
			if (sepPos != -1)
			{
				strncpy(titolo, c, sepPos - 1);
			}

			//search for second pointer
			char* p2 = strstr(p+1, ";");
			sepPos = (p2 - p) + 1;
			if (sepPos != -1)
			{
				strncpy(autore, p+2, sepPos-3);
			}

			printf("Titolo libro: %s\n", titolo);
			printf("Autore libro: %s\n", autore);
			printf("\n");
			lns++;
			memset(c, 0, sizeof(c));
		}

		fclose(f);
		printf("%d lines", lns);
	}
	return 0;
}

int searchInString(const char str[], const char delim)
{
	int out = -1;
	int i = 0;
	int len = strlen(str);
	while (i < len && out != -1)
	{
		if (str[i] == delim)
			out = i;
		i++;
	}
	return out;
}