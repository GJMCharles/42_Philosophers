/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grcharle <grcharle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 02:51:01 by grcharle          #+#    #+#             */
/*   Updated: 2025/08/02 16:03:33 by grcharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_words_count(char const *s, char c)
{
	size_t	count;
	int		ok;

	count = 0;
	ok = 0;
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			ok = 0;
		else if (ok == 0 && (unsigned char)*s != (unsigned char)c)
		{
			ok = 1;
			count += 1;
		}
		s += 1;
	}
	return (count);
}

static char	*extract_word(char const *s, size_t start, size_t pos)
{
	char	*tmp;

	tmp = (char *) malloc(((pos - start) + 1) * sizeof(char));
	if (!tmp)
		return (0);
	(void) ft_strlcpy(tmp, (s + start), (pos - start + 1));
	return (tmp);
}

static char	*get_pos_word(char const *s, char c, size_t *pos)
{
	size_t	i;
	int		found;
	size_t	start;

	i = *pos;
	found = 0;
	start = 0;
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c || s[i] == '\0')
		{
			if (found == 1)
				break ;
			found = 0;
		}
		else if (found == 0 && (unsigned char)s[i] != (unsigned char)c)
		{
			found = 1;
			start = i;
		}
		i += 1;
	}
	*pos = i;
	return (extract_word(s, start, i));
}

static void	*free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		i += 1;
	while (i--)
		free(tab[i]);
	return (free(tab), (void *)0);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	w_count;
	size_t	pos;

	w_count = get_words_count(s, c);
	tab = (char **) malloc((w_count + 1) * sizeof(char *));
	if (!tab)
		return (0);
	pos = 0;
	tab[w_count] = 0;
	i = 0;
	while (i < w_count)
	{
		tab[i] = get_pos_word(s, c, &pos);
		if (!tab[i])
			return ((char **) free_tab(tab));
		i += 1;
	}
	return (tab);
}

/*int	main(void)
{
	char	**tab;
	int	i;

	tab = ft_split(" test 1 toto 42 Mr.Coco 4_YOLO! XD   !", ' ');
	if (!tab)
		return (1);
	i = 0;
	while(tab[i])
	{
		printf("#> %s\n", tab[i]);
		i += 1;
	}
	free_tab(tab);
	return (0);
}*/
