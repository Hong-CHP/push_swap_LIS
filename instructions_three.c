/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_three.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hporta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:51:27 by hporta-c          #+#    #+#             */
/*   Updated: 2025/05/28 11:51:30 by hporta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
