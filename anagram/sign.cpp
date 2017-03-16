#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define WORDMAX 100

int charcmp(const char *x, const char *y)
{
	return *x - *y;
}

int main()
{
	char word[WORDMAX], sig[WORDMAX];
	while (scanf("%s", word) != EOF)
	{
		strcpy(sig, word);
		qsort(sig, strlen(sig), sizeof(char), (__compar_fn_t)charcmp);
		printf("%s %s\n", sig, word);
	}

	return 0;
}
