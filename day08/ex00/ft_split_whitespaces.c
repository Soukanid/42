#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int countWord(char *s)
{
	int i;
	int c;
	
	i = 0;
	c = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
		{
			while (s[i] != ' ' && s[i] != '\t' && s[i] != '\n' && s[i])
				i++;
			c++;
		}
		while(s[i] == ' ' || s[i] == '\t' || s[i] == '\n' && s[i] )
		{
			i++;
		}
	}
	return (c);
}

char **allocateWords(char *s ,int arrayLen)
{
	int i;
	int c;
	int j;
	int l;
	int h;
	char **res = malloc(sizeof(char *) * (arrayLen + 1));
	
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
		{
			h = i;
			c = 0;
			while (s[i] != ' ' && s[i] != '\t' && s[i] != '\n' && s[i])
			{
				i++;
				c++;
			}
			l = 0;
			res[j] = malloc (sizeof(char) * c + 1);
			while(l < c)
			{
				res[j][l] = s[h + l];
				l++;
			}
			res[j][l] = '\0';
			j++;
		}
		while(s[i] == ' ' || s[i] == '\t' || s[i] == '\n' && s[i] )
		{
			i++;
		}
	}
	return (res);
}
char **ft_split_whitespaces(char *str)
{
	int arrayLen;
	
	arrayLen = countWord(str);
	return (allocateWords(str,arrayLen));
}

int main()
{
	char **s;
	int i;
	
	i = 0;
	s = ft_split_whitespaces("soukaina nidbella is the greatest");
	while (s[i])
	{
		printf ("%s     ",s[i]);
		i++;
	}
}
