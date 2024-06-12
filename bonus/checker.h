/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-abdi <ael-abdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 02:16:39 by ael-abdi          #+#    #+#             */
/*   Updated: 2024/05/15 15:43:23 by ael-abdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct stack
{
	int				content;
	int				index;
	int				pos;
	struct stack	*next;
}	t_stack;

char	**ft_split(char const *s, char c);
long	ft_atoi(const char *str);
void	jus_error(char *s);
t_stack	*ft_lstnew(int content);
void	check_space(char *s);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);
void	swap_a_b(t_stack **list);
void	swap_ra_rb(t_stack **a);
int		ft_size(t_stack *a);
void	swap_rra_rrb(t_stack **list);
void	push_to_a(t_stack **a, t_stack **b);
void	push_to_b(t_stack **a, t_stack **b);
void	algo_to_a(t_stack **a, t_stack **b);
void	algo_to_b(t_stack **a, t_stack **b);
int		check_sort(t_stack *a);
void	ft_free(t_stack **list);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
int		search_new_line(const char *s, int c);
void	check_mouv(t_stack **a, t_stack **b);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	swap_ss(t_stack **a, t_stack **b);
void	swap_rrr(t_stack **a, t_stack **b);
void	check_mouv1(t_stack **a, t_stack **b, char *mouv);

#endif