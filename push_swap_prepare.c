/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_prepare.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hporta-c <hporta-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:31:08 by hporta-c          #+#    #+#             */
/*   Updated: 2025/05/28 13:56:03 by hporta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_unmarked_nums_into_b(t_stack *a, t_stack *b, t_unmarked *unmarked)
{
	int	val;
	int	size;
	int	i;

	i = 0;
	size = a->size;
	while (i < size)
	{
		val = *(a->top->value);
		check_before(a, b, val);
		if (is_obj_unmarked(unmarked, val))
			pb(a, b);
		else
		{
			if (b->size > 2
				&& *(b->top->value) < *(b->top->next->value)
				&& *(b->top->value) < *(b->top->next->next->value))
				rr(a, b);
			else
				ra(a);
		}
		i++;
	}
}

t_unmarked	*find_unmarked_nums(t_unmarked *unmarked, int *flag, int *ar, int s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < s)
	{
		if (flag[i] != 1)
		{
			unmarked->unmarked_nums[j] = ar[i];
			j++;
		}
		i++;
	}
	unmarked->unmarked_size = j;
	return (unmarked);
}

t_unmarked	*allocate_and_fill_unmarked(int *flags, int *arr_ord, int size)
{
	t_unmarked	*unmarked_nbs;

	unmarked_nbs = malloc(sizeof(t_unmarked));
	if (!unmarked_nbs)
		return (NULL);
	unmarked_nbs->unmarked_nums = malloc(sizeof(int) * size);
	if (!unmarked_nbs->unmarked_nums)
	{
		free(unmarked_nbs);
		return (NULL);
	}
	find_unmarked_nums(unmarked_nbs, flags, arr_ord, size);
	return (unmarked_nbs);
}

void	rotate_min_to_top(t_stack *stack_a, int min)
{
	int	index;
	int	cost;

	index = get_index(stack_a, min);
	if (index == 0)
		return ;
	cost = calc_rot_cost(stack_a->size, index);
	while (cost > 0)
	{
		ra(stack_a);
		cost--;
	}
	while (cost < 0)
	{
		rra(stack_a);
		cost++;
	}
}

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	int			*flags;
	int			*arr_ord;
	t_unmarked	*unmarked_nbs;
	int			min;

	arr_ord = stack_mapping_arr_ord(stack_a);
	flags = stack_mapping_arr_flags(stack_a);
	unmarked_nbs = allocate_and_fill_unmarked(flags, arr_ord, stack_a->size);
	if (unmarked_nbs->unmarked_size == 0)
		return ;
	push_unmarked_nums_into_b(stack_a, stack_b, unmarked_nbs);
	push_swap_back(stack_a, stack_b);
	get_sort_arr(stack_a->size, arr_ord);
	min = arr_ord[0];
	rotate_min_to_top(stack_a, min);
	free(flags);
	free(arr_ord);
	free(unmarked_nbs->unmarked_nums);
	free(unmarked_nbs);
}
