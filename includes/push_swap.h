/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flda-sil <flda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 21:12:00 by flda-sil          #+#    #+#             */
/*   Updated: 2022/01/14 15:15:55 by flda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define DEBUGER 1
# define TRUE 1
# define FALSE 0
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <get_next_line.h>
# include <stdio.h>

typedef struct s_stack
{
	int				id;
	int				value;
	struct s_stack	*next;
	struct s_stack	*before;
}	t_stack;

typedef struct s_push_swap
{
	t_stack	*a;
	t_stack	*b;
	int		mid_point;
	int		qnt_element_a;
	int		qnt_element_b;
	int		next_id;
	int		double_action;
	int		active_id;
	int		*array;
	int		array_size;
	int		error;
	int		mode;
}	t_push_swap;

enum e_errors
{
	E_SUCCESS = 0,
	E_IS_NOT_NUMBER,
	E_OUT_OF_INT_LIMIT,
	E_DUPLICATE_NUMBER
};

enum e_direction
{
	E_ROTATE_UP = 1,
	E_ROTATE_DOWN
};

enum e_stack
{
	A = -1,
	B = 1
};

enum e_mode
{
	CHECKER = -1,
	SORT = 1
};
//////////SWAP////////

/*
	@brief	Swap the first 2 elements at the top of stack a.
*/
void		sa(t_push_swap *push_swap);

/*
	@brief	Swap the first 2 elements at the top of stack b.
*/
void		sb(t_push_swap *push_swap);

/*
	@brief	Swap the first 2 elements at the top of stack a and b.
*/
void		ss(t_push_swap *push_swap);

//////////PUSH////////

/*
	@brief	Push B - take the first element of the top of A and put
			it a the top of B
*/
void		pb(t_push_swap *push_swap);

/*
	@brief	Push A - take the first element of the top of B and put it
			a the top of A
*/
void		pa(t_push_swap *push_swap);

//////////ROTATE////////

/*
	@brief	Shift up all elements of stack A by 1. The stack's
			Top element comes to Bottom
*/
void		ra(t_push_swap *push_swap);

/*
	@brief	Shift Down all elements of stack A by 1. The stack's
			Bottom element comes to Top
*/
void		rra(t_push_swap *push_swap);

/*
	@brief	Shift up all elements of stack B by 1. The stack's
			Top element comes to Bottom
*/
void		rb(t_push_swap *push_swap);

/*
	@brief	Shift Down all elements of stack B by 1. The stack's
			Bottom element comes to Top
*/
void		rrb(t_push_swap *push_swap);

/*
	@brief	ra and rb a the same time
*/
void		rr(t_push_swap *push_swap);

/*
	@brief	rra and rrb a the same time
*/
void		rrr(t_push_swap *push_swap);

void		print_stacks(t_push_swap push_swap);
void		sort_list(t_push_swap *push_swap);

//////////CHECKS////////

int			check_param(t_push_swap *push_swap, char *params[], int size);

//////////STACK ACTIONS////////

void		add_to_stack(t_push_swap *push_swap, int value);
int			is_in_stack(t_push_swap *push_swap, int value);
void		push_to_stack(t_push_swap *push_swap, char stack);
void		rotate_stack_up(t_push_swap *push_swap, char stack);
void		rotate_stack_down(t_push_swap *push_swap, char stack);
t_stack		*get_stack(t_push_swap *push_swap, char stack);
int			get_direction(t_push_swap *push_swap, t_stack *from);
void		sort_array(int *tab, int size);
void		set_array(t_push_swap *push_swap, t_stack *stack);
int			get_chunk_size(t_push_swap *push_swap, t_stack *from);
void		push_lower_chunk(t_push_swap *push_swap, char from, char to);
void		push_higher_chunk(t_push_swap *push_swap, char from, char to);
void		swap_stack(t_push_swap *push_swap, char stack);
void		free_stacks(t_push_swap *push_swap);

//////////SORT////////
void		sort(t_push_swap *push_swap);
void		sort_three(t_push_swap *push_swap);
int			is_sorted(t_push_swap *push_swap);
//////////CHUNK////////

void		push_to(t_push_swap *push_swap, t_stack *from, char to, int d);
void		bring_chunk_up(t_push_swap *push_swap, char stack);

//////////UTILS////////

void		ft_bzero(void *addr, int bytes);
int			print_error(int error);
long int	ft_atoi(const char *nptr);
void		*ft_calloc(size_t nmemb, size_t size);
size_t		ft_strlen(const char *s);
int			is_in(int *array, int n, int size);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

#endif