/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-abdi <ael-abdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:03:26 by ael-abdi          #+#    #+#             */
/*   Updated: 2024/04/01 02:41:04 by ael-abdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_size(*a);
	if (size == 1)
		exit(0);
	else if (size == 2)
		sort_2(a, 'a');
	else if (size == 3)
		sort_3(a);
	else if (size == 4)
		sort_4(a, b);
	else if (size == 5)
		sort_5(a, b);
	else
		algo_to_b(a, b, 0);
}

void	algo_to_a(t_stack **a, t_stack **b)
{
	int	size;
	int	max;

	size = ft_size(*b);
	max = 0;
	while (size)
	{
		index_list(*b, 0);
		max = max_index(*b);
		if (max <= size / 2)
		{
			while (max--)
				swap_ra_rb(b, 'b');
			push_to_a(a, b);
		}
		else
		{
			while (max++ < size - 1)
				swap_rra_rrb(b, 'b');
			swap_rra_rrb(b, 'b');
			push_to_a(a, b);
		}
		size--;
	}
}

void	algo_to_b(t_stack **a, t_stack **b, int i)
{
	int		size;
	int		dep;
	t_stack	*tmp;

	index_list(*a, 0);
	size = ft_size(*a);
	if (size <= 100)
		dep = 20;
	else
		dep = 30;
	while (*a)
	{
		tmp = *a;
		if (tmp->pos <= i)
			(push_to_b(a, b), i++);
		else if (tmp->pos < i + dep)
		{
			(push_to_b(a, b), swap_ra_rb(b, 'b'));
			i++;
		}
		else
			swap_ra_rb(a, 'a');
	}
	algo_to_a(a, b);
}
