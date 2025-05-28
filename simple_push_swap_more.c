/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_push_swap_more.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hporta-c <hporta-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:06:18 by hporta-c          #+#    #+#             */
/*   Updated: 2025/05/28 13:54:27 by hporta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_mins_pos_in_simple(t_stack *stack_a, int num)
{
	t_node	*cur;
	int		pos;
	int		feet;

	pos = 1;
	cur = stack_a->top;
	while (cur)
	{
		if (num == *(cur->value))
			break ;
		pos++;
		cur = cur->next;
	}
	if (pos > (stack_a->size + 1) / 2)
		feet = stack_a->size + 1 - pos;
	else
		feet = pos - 1;
	return (feet);
}

int	find_shortest_from_mins(int *mins_path, int size)
{
	int	min;
	int	min_index;
	int	i;

	if (size == 2)
	{
		if (mins_path[0] < mins_path[1])
			return (0);
		else
			return (1);
	}
	i = 1;
	min = mins_path[0];
	min_index = 0;
	while (i < size)
	{
		if (min > mins_path[i])
		{
			min = mins_path[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

void	simple_rotate(t_stack *stack_a, t_stack *stack_b, int val, int real_pos)
{
	if (real_pos <= (stack_a->size + 1) / 2)
	{
		while (*(stack_a->top->value) != val)
		{
			if (stack_b->size > 2
				&& *(stack_b->top->value) < *(stack_b->top->next->value)
				&& *(stack_b->top->value) < *(stack_b->top->next->next->value))
				rr(stack_a, stack_b);
			else
				ra(stack_a);
		}
	}
	else
	{
		while (*(stack_a->top->value) != val)
		{
			if (stack_b->size > 2
				&& *(stack_b->top->value) < *(stack_b->top->next->value)
				&& *(stack_b->top->value) < *(stack_b->top->next->next->value))
				rrr(stack_a, stack_b);
			else
				rra(stack_a);
		}
	}
}

void	check_before(t_stack *stack_a, t_stack *stack_b, int val)
{
	int	real_pos;

	real_pos = get_real_pos(stack_a, val);
	if (real_pos == 2)
	{
		if (stack_b->size >= 2
			&& *(stack_b->top->value) < *(stack_b->top->next->value))
			ss(stack_a, stack_b);
	}
	else if (stack_b->size == 2
		&& *(stack_b->top->value) < *(stack_b->top->next->value))
		sb(stack_b);
	else if (stack_b->size > 2
		&& *(stack_b->top->value) < *(stack_b->top->next->value)
		&& *(stack_b->top->value) > *(stack_b->top->next->next->value))
		sb(stack_b);
	else if (stack_b->size > 2
		&& *(stack_b->top->value) < *(stack_b->top->next->value)
		&& *(stack_b->top->value) < *(stack_b->top->next->next->value))
		rb(stack_b);
}

void	get_arr_min_check_rotate_push(t_stack *a, t_stack *b, int *ar, int *m)
{
	int	i;
	int	min_index;
	int	real_pos;

	while (a->size > 3)
	{
		i = 0;
		while (a->size - i > 3)
		{
			ar = creat_array_from_stack(a, ar);
			get_sort_arr(a->size, ar);
			m[i] = find_mins_pos_in_simple(a, ar[i]);
			i++;
		}
		if (i >= 2)
			min_index = find_shortest_from_mins(m, i);
		else
			min_index = 0;
		check_before(a, b, ar[min_index]);
		real_pos = get_real_pos(a, ar[min_index]);
		simple_rotate(a, b, ar[min_index], real_pos);
		pb(a, b);
		check_before(a, b, ar[min_index]);
	}
}
