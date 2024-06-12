/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-abdi <ael-abdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:43:32 by ael-abdi          #+#    #+#             */
/*   Updated: 2024/05/14 17:31:05 by ael-abdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack **list, char c)
{
	if ((*list)->content > (*list)->next->content)
		swap_a_b(list, c);
	return ;
}

void	sort_3(t_stack **list)
{
	t_stack	*tmp;
	int		size;

	tmp = max_list(*list);
	index_list(*list, 0);
	size = ft_size(*list);
	if (tmp->index == size - 1)
		sort_2(list, 'a');
	else if (tmp == *list)
	{
		swap_ra_rb(list, 'a');
		sort_2(list, 'a');
	}
	else
	{
		swap_rra_rrb(list, 'a');
		sort_2(list, 'a');
	}
}

void	sort_4(t_stack **a, t_stack **b)
{
	t_stack	*min;

	min = min_list(*a);
	index_list(*a, 0);
	while ((*a)->index < min->index)
	{
		swap_ra_rb(a, 'a');
	}
	push_to_b(a, b);
	sort_3(a);
	push_to_a(a, b);
}

void	sort_5(t_stack **a, t_stack **b)
{
	t_stack	*min;
	int		size;

	index_list(*a, 0);
	min = min_list(*a);
	size = ft_size(*a);
	if (min->index == size - 1)
		swap_rra_rrb(a, 'a');
	while ((*a)->index < min->index)
	{
		swap_ra_rb(a, 'a');
	}
	push_to_b(a, b);
	sort_4(a, b);
	push_to_a(a, b);
}
