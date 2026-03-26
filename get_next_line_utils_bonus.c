/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoped2 <joaoped2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:54:37 by joaoped2          #+#    #+#             */
/*   Updated: 2022/11/18 15:48:05 by joaoped2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*
** ft_strlen:
** Mede o tamanho da string até '\0'.
** Aceita NULL e devolve 0 para simplificar chamadas defensivas.
*/
size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*
** ft_strchr:
** Procura a primeira ocorrência de c em s.
** Devolve: ponteiro para o caráter encontrado, ou NULL se não existir.
*/
char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (NULL);
}

/*
** ft_strdup:
** Duplica string para memória dinâmica.
** Devolve: ponteiro para copia (free por quem chama) ou NULL em erro.
*/
char	*ft_strdup(const char *s)
{
	char	*new;
	char	*tmp;

	new = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!new)
		return (NULL);
	tmp = new;
	while (*s)
		*tmp++ = *s++;
	*tmp = 0;
	return (new);
}

/*
** ft_strjoin:
** Concatena s1 + s2 numa nova string alocada.
** Trata entradas NULL de forma segura.
** Devolve: nova string (free por quem chama) ou NULL em erro.
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	char	*tmp;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	tmp = new;
	while (*s1)
		*tmp++ = *s1++;
	while (*s2)
		*tmp++ = *s2++;
	*tmp = 0;
	return (new);
}

/*
** ft_substr:
** Cria substring a partir de s, em start, com máximo len bytes.
** Se start estiver fora de s, devolve string vazia.
** Devolve: nova substring (free por quem chama) ou NULL em erro.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subst;
	char	*tmp;
	size_t	size;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (NULL);
	subst = tmp;
	s += start;
	while (*s && len--)
		*tmp++ = *s++;
	*tmp = 0;
	return (subst);
}
