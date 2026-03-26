/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 23:29:11 by marvin            #+#    #+#             */
/*   Updated: 2026/03/24 23:29:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	open_file(int ac, char **av, int *fd)
{
	if (ac != 2)
	{
		printf("Uso: %s <ficheiro>\n", av[0]);
		return (1);
	}
	*fd = open(av[1], O_RDONLY);
	if (*fd < 0)
		return (perror("Erro ao abrir ficheiro"), 1);
	return (0);
}

static void	print_file_lines(int fd)
{
	char	*line;
	int		i;

	i = 1;
	line = get_next_line(fd);
	while (line)
	{
		printf("%d: %s", i, line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
}

int	main(int ac, char **av)
{
	int		fd;

	if (open_file(ac, av, &fd) != 0)
		return (1);
	print_file_lines(fd);
	close(fd);
	return (0);
}
