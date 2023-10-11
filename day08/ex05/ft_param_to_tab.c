#include "ft_stock_par.h"
#include <stdlib.h>

int ft_len(char *s)
{
	int i;
	 
	i = 0;
	while(s[i])
		i++;
	return(i);
}

char *ft_strdup(char *s)
{
	int i;
	int j;
	
	char *res = malloc (sizeof(char) * ft_len(s));
	while(s[j])
	{
		res[j] = s[j];
		j++;
	}
	res[j] = '\0';
	return (res);
}
struct s_stock_par *ft_param_to_tab(int ac, char **av)
{
	int i;
	t_stock_par	*tab;
	
	i = 0;
	tab = (s_stock_par *)malloc(sizeof(t_stock_par) * (ac + 1));
	while (av[i])
	{
		tab[i].size_param = ft_len(av[i]);
		tab[i].str = av[i];
		tab[i].copy = ft_strdup(av[i]);
		tab[i].tab = ft_split_whitespaces(av[i]);
		i++;
	}
	tab[i].str = NULL;
	return (tab);
}

int main (int ac ,char **av)
{
	ft_param_to_tab(ac, av);
}
