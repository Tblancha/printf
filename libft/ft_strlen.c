/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjorgen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 22:16:47 by brjorgen          #+#    #+#             */
/*   Updated: 2019/04/05 22:16:58 by brjorgen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t		ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		if (!(s[++i]))
			return (i);
		if (!(s[++i]))
			return (i);
		if (!(s[++i]))
			return (i);
		if (!(s[++i]))
			return (i);
	}
	return (i);
}
