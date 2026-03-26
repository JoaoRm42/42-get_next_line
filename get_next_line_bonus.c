/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:54:52 by joaoped2          #+#    #+#             */
/*   Updated: 2026/03/24 23:31:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*
** add:
** Junta o conteúdo de s2 ao acumulador s1.
** Em caso de sucesso, s1 passa a apontar para a nova string e a anterior
** e libertada.
** Devolve: 1 em sucesso, 0 em erro de alocação.
*/
static int	add(char **s1, char *s2)
{
	char	*tmp;

	tmp = ft_strjoin(*s1, s2);
	if (!tmp)
		return (0);
	free(*s1);
	*s1 = tmp;
	return (1);
}

/*
** split_line:
** Divide o acumulador em duas partes no '\n':
** - out recebe a linha completa (inclui '\n')
** - line fica com o resto (ou NULL se não houver resto)
** Devolve: 1 em sucesso, 0 em erro de alocação.
*/
static int	split_line(char **line, char *nl, char **out)
{
	char	*tmp;

	*out = ft_substr(*line, 0, nl - *line + 1);
	if (!*out)
		return (0);
	tmp = NULL;
	if (*(nl + 1))
		tmp = ft_strdup(nl + 1);
	if (*(nl + 1) && !tmp)
	{
		free(*out);
		return (0);
	}
	free(*line);
	*line = tmp;
	return (1);
}

/*
** save_and_clear:
** Extrai a próxima linha pronta a devolver.
** Se existir '\n', corta no ponto certo e guarda resto para a chamada seguinte.
** Se não existir '\n', devolve todo o acumulado e limpa o estado interno.
** Devolve: linha alocada (free por quem chama) ou NULL em erro.
*/
static char	*save_and_clear(char **line)
{
	char	*nl;
	char	*out;

	nl = ft_strchr(*line, '\n');
	if (nl && !split_line(line, nl, &out))
		return (NULL);
	if (nl)
		return (out);
	out = ft_strdup(*line);
	if (!out)
		return (NULL);
	free(*line);
	*line = NULL;
	return (out);
}

/*
** read_and_add:
** Lê do fd e acumula dados em line até encontrar '\n' ou EOF.
** Se line já tiver '\n', evita leitura extra.
** Devolve:
** - > 0: leu bytes
** - 0: EOF
** - -1: erro de `read`/`malloc`
*/
static int	read_and_add(char **line, int fd)
{
	ssize_t	bytes_read;
	char	*buf;

	if (*line && ft_strchr(*line, '\n'))
		return (1);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	bytes_read = read(fd, buf, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buf[bytes_read] = '\0';
		if (!*line)
		{
			*line = ft_strdup("");
			if (!*line)
				return (free(buf), -1);
		}
		if (!add(line, buf))
			return (free(buf), -1);
		if (ft_strchr(buf, '\n'))
			break ;
		bytes_read = read(fd, buf, BUFFER_SIZE);
	}
	return (free(buf), bytes_read);
}

/*
** get_next_line (bonus):
** Igual ao obrigatório, mas com estado separado por fd:
** static char *string[MAX_FD].
** Permite chamadas intercaladas em vários descritores
** sem mistura de estado.
** Devolve: linha com '\n' quando aplicável, ou NULL em EOF/erro.
*/
char	*get_next_line(int fd)
{
	static char	*string[MAX_FD];
	char		*ret_line;
	int			br;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	br = read_and_add(&string[fd], fd);
	if (br < 0 || !string[fd] || !*string[fd])
		return (free(string[fd]), string[fd] = NULL, NULL);
	ret_line = save_and_clear(&string[fd]);
	if (!ret_line)
		return (free(string[fd]), string[fd] = NULL, NULL);
	return (ret_line);
}
