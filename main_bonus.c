/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 23:31:25 by marvin            #+#    #+#             */
/*   Updated: 2026/03/24 23:31:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	print_line(char *prefix, char *line)
{
	if (line)
		printf("%s%s", prefix, line);
	else
		printf("%s(NULL)\n", prefix);
}

static int	open_files(int ac, char **av, int *fd1, int *fd2)
{
	if (ac != 3)
	{
		printf("Uso: %s <ficheiro1> <ficheiro2>\n", av[0]);
		return (1);
	}
	*fd1 = open(av[1], O_RDONLY);
	*fd2 = open(av[2], O_RDONLY);
	if (*fd1 < 0 || *fd2 < 0)
	{
		perror("Erro ao abrir ficheiros");
		if (*fd1 >= 0)
			close(*fd1);
		if (*fd2 >= 0)
			close(*fd2);
		return (1);
	}
	return (0);
}

static void	read_both(int fd1, int fd2)
{
	char	*line1;
	char	*line2;

	line1 = get_next_line(fd1);
	line2 = get_next_line(fd2);
	while (line1 || line2)
	{
		if (line1)
			print_line("fd1: ", line1);
		if (line2)
			print_line("fd2: ", line2);
		free(line1);
		free(line2);
		line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);
	}
}

int	main(int ac, char **av)
{
	int		fd1;
	int		fd2;

	if (open_files(ac, av, &fd1, &fd2) != 0)
		return (1);
	read_both(fd1, fd2);
	close(fd1);
	close(fd2);
	return (0);
}
