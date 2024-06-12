/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_mov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-abdi <ael-abdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 18:31:43 by ael-abdi          #+#    #+#             */
/*   Updated: 2024/03/30 01:06:17 by ael-abdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a_b(t_stack **list, char c)
{
	int	swap;

	if (!list || !*list)
		return ;
	swap = (*list)->content;
	(*list)->content = (*list)->next->content;
	(*list)->next->content = swap;
	if (c == 'a')
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}

void	swap_ra_rb(t_stack **a, char c)
{
	t_stack	*swap;
	t_stack	*index;

	index = *a;
	swap = *a;
	if ((*a)->next != NULL)
	{
		*a = (*a)->next;
		while (index->next != NULL)
		{
			index = index->next;
		}
		index->next = swap;
		swap ->next = NULL;
		if (c == 'a')
			write(1, "ra\n", 3);
		else
			write(1, "rb\n", 3);
	}
}

void	swap_rra_rrb(t_stack **list, char c)
{
	t_stack	*tmp;
	t_stack	*last;

	tmp = *list;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp ->next = NULL;
	last->next = *list;
	*list = last;
	if (c == 'a')
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}

void	push_to_b(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = *a;
	(*a) = (*a)->next;
	if (!(*b))
	{
		(*b) = tmp;
		(*b)->next = NULL;
	}
	else
	{
		tmp->next = *b;
		*b = tmp;
	}
	write(1, "pb\n", 3);
}

void	push_to_a(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = *b;
	(*b) = (*b)->next;
	if (!(*a))
	{
		(*a) = tmp;
		(*a)->next = NULL;
	}
	else
	{
		tmp->next = *a;
		*a = tmp;
	}
	write(1, "pa\n", 3);
}
