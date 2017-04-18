/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafabre <mafabre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 17:05:36 by mafabre           #+#    #+#             */
/*   Updated: 2017/04/18 17:15:51 by mafabre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char		*save_file(char *file)
{
	int		fd;
	int		ret;
	char	*tab;

	ret = 0;
	tab = 0;
	fd = open(file, O_RDONLY, 0);
	if (fd == -1)
	{
		printf("hello\n");
		return (NULL);
	}
	ret = read(fd, tab, BUF_SIZE);
	printf("coucou\n");
	printf("%s", tab);
	close(fd);
	return (tab);
}

int   main(int ac, char **av)
{
  char *cor;

  if (ac == 2)
  {
    cor = save_file(av[1]);
		printf("coucou\n");
    printf("%s", cor);
  }
  ft_printf("Coucou\n");
}
