/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_mov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-abdi <ael-abdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 18:31:43 by ael-abdi          #+#    #+#             */
/*   Updated: 2024/05/15 19:06:14 by ael-abdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap_a_b(t_stack **list)
{
	int	swap;

	if (!list || !*list)
		return ;
	if ((*list)->next)
	{
		swap = (*list)->content;
		(*list)->content = (*list)->next->content;
		(*list)->next->content = swap;
	}
}

void	swap_ra_rb(t_stack **a)
{
	t_stack	*swap;
	t_stack	*index;

	if (!a || !*a)
		return ;
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
	}
}

void	swap_rra_rrb(t_stack **list)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!list || !*list)
		return ;
	tmp = *list;
	while (tmp->next && tmp->next->next)
		tmp = tmp->next;
	if (tmp->next)
	{
		last = tmp->next;
		tmp->next = NULL;
		last->next = *list;
		*list = last;
	}
}

void	push_to_b(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (ft_size(*a) == 0)
		return ;
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
}

void	push_to_a(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (ft_size(*b) == 0)
		return ;
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
}
