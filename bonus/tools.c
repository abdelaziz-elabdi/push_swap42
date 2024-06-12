/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-abdi <ael-abdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:30:27 by ael-abdi          #+#    #+#             */
/*   Updated: 2024/03/30 02:30:37 by ael-abdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	jus_error(char *s)
{
	int	j;

	j = 0;
	if (!s)
		return ;
	while (s[j])
	{
		write(2, &s[j++], 1);
	}
	exit(EXIT_FAILURE);
}

t_stack	*ft_lstnew(int content)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node -> content = content;
	node -> next = NULL;
	return (node);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*ben;

	if (!lst || !new)
		return ;
	ben = ft_lstlast(*lst);
	if (*lst)
		ben -> next = new;
	else
		*lst = new;
}

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*ben;

	if (!lst)
		return (NULL);
	ben = lst;
	while ((ben -> next) != 0)
	{
		ben = ben -> next;
	}
	return (ben);
}
