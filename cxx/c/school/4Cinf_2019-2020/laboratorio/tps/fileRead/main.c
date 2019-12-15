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
		memset(c,0,sizeof(buf));
		int lns = 0;
		while (fgets(c, 1000, f) != NULL)
		{
			//declare buffer var array
			char buf[1000];
			//zerofill buffer
			memset(buf,0,sizeof(buf));

			strcpy(buf, c);
			//print temp buffer
			printf("%s", buf);

			//
			char tmp[1000];
			int sepPos = searchInString(buf, ';');

			if (sepPos != -1) {
				printf("%d\n", sepPos);
				//strncpy(tmp, c, sepPos);
			}

			printf("%s", tmp);

			lns++;
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
	while (i < len && out != -1) {
		if (str[i] == delim) out = i;
		i++;
	}
	return out;
}