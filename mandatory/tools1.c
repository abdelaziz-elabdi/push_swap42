/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-abdi <ael-abdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:48:50 by ael-abdi          #+#    #+#             */
/*   Updated: 2024/05/14 14:49:58 by ael-abdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *str)
{
	int		l;
	int		mr;
	long	ben;

	l = 0;
	mr = 1;
	ben = 0;
	while (str[l] == 32)
		l++;
	if (str[l] == '-' || str[l] == '+')
	{
		if (str[l] == '-')
			mr = -mr;
		l++;
	}
	while (str[l] >= '0' && str[l] <= '9')
	{
		ben = ben * 10 + str[l] - 48;
		if (mr * ben > 2147483647 || mr * ben < -2147483648)
			jus_error("Error\n");
		l++;
	}
	return (mr * ben);
}

void	check_space(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '\0')
		jus_error("Error\n");
	while (s[i] && s[i] == ' ')
		i++;
	if (s[i] == '\0')
		jus_error("Error\n");
}

int	ft_size(t_stack *a)
{
	int	i;

	i = 0;
	while (a)
	{
		a = a->next;
		i++;
	}
	return (i);
}

void	ft_free(t_stack **list)
{
	t_stack	*tmp;

	tmp = *list;
	while (tmp)
	{
		free(tmp);
		tmp = tmp ->next;
	}
	free (tmp);
}
