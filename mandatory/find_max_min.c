/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max_min.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-abdi <ael-abdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:56:29 by ael-abdi          #+#    #+#             */
/*   Updated: 2024/03/30 00:36:28 by ael-abdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (tmp->content < a->content)
				return (0);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (1);
}

void	index_list(t_stack *list, int index)
{
	t_stack	*tmp1;
	t_stack	*tmp2;
	int		k;

	tmp1 = list;
	while (tmp1)
	{
		tmp1->index = index++;
		tmp1 = tmp1->next;
	}
	tmp1 = list;
	while (tmp1)
	{
		k = 0;
		tmp2 = list;
		while (tmp2)
		{
			if (tmp1->content < tmp2->content)
				k++;
			tmp2 = tmp2->next;
		}
		tmp1->pos = k;
		tmp1 = tmp1->next;
	}
}

t_stack	*max_list(t_stack *list)
{
	t_stack	*k;

	k = list;
	while (k)
	{
		if (k->content > list->content)
			list = k;
		k = k->next;
	}
	return (list);
}

t_stack	*min_list(t_stack *list)
{
	t_stack	*tmp;

	tmp = list;
	while (list->next)
	{
		list = list->next;
		if (list->content < tmp->content)
			tmp = list;
	}
	return (tmp);
}
