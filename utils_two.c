/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hporta-c <hporta-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:01:07 by hporta-c          #+#    #+#             */
/*   Updated: 2025/06/18 17:12:49 by hporta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_real_pos(t_stack *stack_a, int num)
{
	t_node	*cur;
	int		pos;

	pos = 1;
	cur = stack_a->top;
	while (cur)
	{
		if (num == *(cur->value))
			break ;
		pos++;
		cur = cur->next;
	}
	return (pos);
}

int	is_obj_unmarked(t_unmarked *unmarked_nbs, int val)
{
	int	i;

	i = 0;
	while (i < unmarked_nbs->unmarked_size)
	{
		if (val == unmarked_nbs->unmarked_nums[i])
			return (1);
		i++;
	}
	return (0);
}

int	get_index(t_stack *stack, int val)
{
	t_node	*cur;
	int		index;

	cur = stack->top;
	index = 0;
	while (cur)
	{
		if (*(cur->value) == val)
			return (index);
		cur = cur->next;
		index++;
	}
	return (-1);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}
// void    print_arr(int *arr, int size)
// {
//     int i = 0;
//     while (i < size)
//     {
//         printf("%d, ", arr[i]);
//         i++;
//     }
//     printf("\n");
// }

// void    ft_print_stack(t_stack *stack)
// {
//     t_node *cur;

//     cur = stack->top;
//     while (cur)
//     {
//         printf(" <- %d - > ", *(cur->value));
//         cur = cur->next;
//     }
//     printf("NULL\n");
// }
