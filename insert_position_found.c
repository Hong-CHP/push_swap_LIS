#include "push_swap.h"

int    find_val_insert_place(t_stack *stack_a, int val)
{
    t_node *cur;
    int pos_in_a;

    pos_in_a = 0;
    cur = stack_a->top;
    while (cur->next)
    {
        if (val > *(cur->value) && val < *(cur->next->value))
            return (pos_in_a + 1);
        pos_in_a++;
        cur = cur->next;
    }
    return (-1);
}

int    find_val_insert_place_exp_one(t_stack *stack_a, int val)
{
    t_node *cur;
    int pos_in_a;
    int max;
    int pos;

    max = *(stack_a->top->value);
    cur = stack_a->top;
    pos_in_a = 0;
    pos = 0;
    while (cur)
    {
        if (max < *(cur->value))
        {
            max = *(cur->value);
            pos_in_a = pos;
        }
        pos++;
        cur = cur->next;
    }
    if (pos_in_a == 0)
        return (0);
    else if (pos_in_a == stack_a->size - 1)
        return (0);
    else
        return (pos_in_a + 1);
}

int    find_val_insert_place_exp_two(t_stack *stack_a, int val)
{
    t_node *cur;
    int min;

    cur = stack_a->top;
    if (val < *(cur->value))
    {
        while (cur->next)
            cur = cur->next;
        if (val > *(cur->value))
            return (0);
    }
    return (0);
}

int    find_val_insert_place_exp_three(t_stack *stack_a, int val)
{
    int pos;
    int pos_in_a;
    t_node *cur;
    int min;

    cur = stack_a->top;
    min = *(cur->value);
    pos_in_a = 0;
    pos = 0;
    while (cur)
    {
        if (min > *(cur->value))
        {
            min = *(cur->value);
            pos_in_a = pos;
        }
        pos++;
        cur = cur->next;
    }
    if (pos_in_a == 0)
        return (0);
    else if (pos_in_a == stack_a->size - 1)
        return (0);
    else
        return (pos_in_a + 1); 
}

int    solve_exp_case(t_stack *stack_a, int val)
{
    t_node *cur;
    int max;
    int min;

    max = val;
    min = val;
    cur = stack_a->top;
    while (cur)
    {
        if (max < *(cur->value))
            max = *(cur->value);
        if (min > *(cur->value))
            min = *(cur->value);
        cur = cur->next;
    }
    if (val == max)
        return (find_val_insert_place_exp_one(stack_a, val));
    else if (val == min)
        return (find_val_insert_place_exp_three(stack_a, val));
    else
        return (find_val_insert_place_exp_two(stack_a, val));
}
