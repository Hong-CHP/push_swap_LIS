#include "push_swap.h"

void    sort_two(t_stack *stack)
{
    t_node *first;
    t_node *second;

    first = stack->top;
    second = first->next;
    if (*(first->value) > *(second->value))
        sa(stack);
}

void    ops_sort_three(t_stack *stack, t_node *first, t_node *second, t_node *third)
{
    if (*(first->value) > *(second->value)
        && *(second->value) < *(third->value)
        && *(first->value) < *(third->value))
        sa(stack);
    else if (*(first->value) < *(second->value)
        && *(second->value) > *(third->value)
        && *(first->value) > *(third->value))
        rra(stack);
    else if (*(first->value) > *(second->value)
        && *(first->value) > *(third->value)
        && *(second->value) < *(third->value))
        ra(stack);
    else if (*(first->value) < *(third->value)
        && *(first->value) < *(second->value)
        && *(second->value) > *(third->value))
    {
        sa(stack);
        ra(stack);
    }
    else if (*(first->value) > *(second->value)
        && *(second->value) > *(third->value)) 
    {
        sa(stack);
        rra(stack);
    }
}

void    sort_three(t_stack *stack)
{
    t_node *first;
    t_node *second;
    t_node *third;

    if (!stack || stack->size != 3)
        return ;
    first = stack->top;
    second = first->next;
    third = second->next;
    ops_sort_three(stack, first, second, third);
}

//two malloc need to be free than, free already in func
void    sort_less_than_seven(t_stack *stack_a, t_stack *stack_b)
{
    int *arr;
    int *mins_path;
    mins_path = malloc(sizeof(int) * stack_a->size);
    if (!mins_path)
        return ;
    arr = malloc(sizeof(int) * stack_a->size);
    if (!arr)
        return ;
    get_arr_min_check_rotate_push(stack_a, stack_b, arr, mins_path);
    sort_three(stack_a);
    while (stack_b->size > 0)
        pa(stack_b, stack_a);
    free(mins_path);
    free(arr);
}

void    easy_push_swap(t_stack *stack_a, t_stack *stack_b)
{
    if (stack_a->size <= 1)
        return ;
    if (stack_a->size <= 1)
        return ;
    if (stack_a->size == 2)
        sort_two(stack_a);
    else if (stack_a->size == 3)
        sort_three(stack_a);
    else if (stack_a->size > 3 && stack_a->size <=6)
        sort_less_than_seven(stack_a, stack_b);
}