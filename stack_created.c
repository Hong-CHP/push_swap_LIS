/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_created.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hporta-c <hporta-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:54:17 by hporta-c          #+#    #+#             */
/*   Updated: 2025/06/18 17:20:03 by hporta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*next;

	if (!stack)
		return ;
	node = stack->top;
	while (node)
	{
		next = node->next;
		if (node->value)
			free(node->value);
		free(node);
		node = next;
	}
	stack->top = NULL;
	stack->size = 0;
}

void	ft_push(t_stack *stack, int *value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return ;
	node->value = value;
	node->next = stack->top;
	node->prev = NULL;
	if (stack->top != NULL)
		stack->top->prev = node;
	stack->top = node;
	stack->size++;
}

int	is_dup_value(t_stack *stack, int *value)
{
	t_node	*cur;

	cur = stack->top;
	while (cur)
	{
		if (*value == *(cur->value))
			return (1);
		cur = cur->next;
	}
	return (0);
}

void	simple_complexe_push_swap(t_stack *stack_a, t_stack *stack_b)
{
	if (!check_if_unsort(stack_a) || stack_a->size == 0)
		return ;
	if (stack_a->size <= 6)
		easy_push_swap(stack_a, stack_b);
	else
		push_swap(stack_a, stack_b);
}

// ft_print_stack(&stack_a);
void	get_value_init_stack(int argc, char *argv[], int i)
{
	long		*value;
	t_stack		stack_a;
	t_stack		stack_b;

	value = NULL;
	stack_a = (t_stack){NULL, 0};
	stack_b = (t_stack){NULL, 0};
	while (i < argc)
	{
		value = malloc(sizeof(long));
		if (!value)
			return ;
		*value = ft_atoi(argv[i]);
		if (!check_value_before_push(value, &stack_a))
			return ;
		ft_push(&stack_a, (int *)value);
		i++;
	}
	simple_complexe_push_swap(&stack_a, &stack_b);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
}
