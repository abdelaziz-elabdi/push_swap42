/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-abdi <ael-abdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:50:11 by ael-abdi          #+#    #+#             */
/*   Updated: 2024/05/15 10:46:31 by ael-abdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_duplicate(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (tmp->content == a->content)
				jus_error("Error\n");
			tmp = tmp->next;
		}
		a = a->next;
	}
}

void	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		jus_error("Error\n");
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			jus_error("Error\n");
		i++;
	}
}

void	stack_nbr(t_stack **a, int nbr)
{
	t_stack	*new_nbr;

	new_nbr = ft_lstnew(nbr);
	ft_lstadd_back(a, new_nbr);
}

void	check_arg(char **av, int ac, t_stack **a)
{
	char	**arg;
	int		i;
	int		j;
	int		k;

	i = 1;
	while (i < ac)
	{
		j = 0;
		k = 0;
		check_space(av[i]);
		arg = ft_split(av[i], ' ');
		if (arg == NULL)
			jus_error("Error\n");
		while (arg[j])
			is_number(arg[j++]);
		while (k < j)
		{
			(stack_nbr(a, ft_atoi(arg[k])), free(arg[k]));
			k++;
		}
		ft_duplicate(*a);
		free(arg);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac >= 2)
	{
		check_arg(av, ac, &a);
		if (check_sort(a) == 1)
		{
			ft_free(&a);
			return (0);
		}
		push_a(&a, &b);
		ft_free(&a);
	}
}
