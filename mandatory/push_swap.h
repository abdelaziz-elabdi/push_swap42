/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-abdi <ael-abdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 01:18:34 by ael-abdi          #+#    #+#             */
/*   Updated: 2024/05/15 15:42:38 by ael-abdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

typedef struct stack
{
	int				content;
	int				index;
	int				pos;
	struct stack	*next;
}		t_stack;

char	**ft_split(char const *s, char c);
long	ft_atoi(const char *str);
void	check_space(char *s);
void	jus_error(char *s);
t_stack	*ft_lstnew(int content);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);
void	swap_a_b(t_stack **list, char c);
void	swap_ra_rb(t_stack **a, char c);
int		ft_size(t_stack *a);
void	push_a(t_stack **a, t_stack **b);
void	sort_2(t_stack **list, char c);
void	sort_3(t_stack **list);
void	index_list(t_stack *list, int index);
t_stack	*max_list(t_stack *list);
t_stack	*min_list(t_stack *list);
void	swap_rra_rrb(t_stack **list, char c);
void	sort_4(t_stack **a, t_stack **b);
void	push_to_a(t_stack **a, t_stack **b);
void	push_to_b(t_stack **a, t_stack **b);
void	sort_5(t_stack **a, t_stack **b);
void	algo_to_a(t_stack **a, t_stack **b);
void	algo_to_b(t_stack **a, t_stack **b, int i);
int		max_index(t_stack *list);
int		check_sort(t_stack *a);
void	ft_free(t_stack **list);

#endif