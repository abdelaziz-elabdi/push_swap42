/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mouv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-abdi <ael-abdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:35:13 by ael-abdi          #+#    #+#             */
/*   Updated: 2024/05/14 20:41:58 by ael-abdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap_ss(t_stack **a, t_stack **b)
{
	swap_a_b(a);
	swap_a_b(b);
}

void	swap_rrr(t_stack **a, t_stack **b)
{
	swap_rra_rrb(a);
	swap_rra_rrb(b);
}

void	check_mouv1(t_stack **a, t_stack **b, char *mouv)
{
	if (ft_strncmp(mouv, "pa\n", 3) == 0)
		push_to_a(a, b);
	else if (ft_strncmp(mouv, "pb\n", 3) == 0)
		push_to_b(a, b);
	else if (ft_strncmp(mouv, "ss\n", 3) == 0)
		swap_ss(a, b);
	else if (ft_strncmp(mouv, "rrr\n", 4) == 0)
		swap_rrr(a, b);
	else
		jus_error("Error\n");
}

void	check_mouv(t_stack **a, t_stack **b)
{
	char	*mouv;

	mouv = get_next_line(0);
	while (mouv)
	{
		if (ft_strncmp(mouv, "sa\n", 3) == 0)
			swap_a_b(a);
		else if (ft_strncmp(mouv, "sb\n", 3) == 0)
			swap_a_b(b);
		else if (ft_strncmp(mouv, "ra\n", 3) == 0)
			swap_ra_rb(a);
		else if (ft_strncmp(mouv, "rb\n", 3) == 0)
			swap_ra_rb(b);
		else if (ft_strncmp(mouv, "rra\n", 4) == 0)
			swap_rra_rrb(a);
		else if (ft_strncmp(mouv, "rrb\n", 4) == 0)
			swap_rra_rrb(b);
		else
			check_mouv1(a, b, mouv);
		free(mouv);
		mouv = get_next_line(0);
	}
}
