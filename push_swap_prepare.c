#include "push_swap.h"

void    push_unmarked_nums_into_b(t_stack *stack_a, t_stack *stack_b, t_unmarked *unmarked_nbs)
{
    int     val;
    int     size;
    int     i;

    i = 0;
    size = stack_a->size;
    while (i < size)
    {
        val = *(stack_a->top->value);
        check_before(stack_a, stack_b, val);
        if (is_obj_unmarked(unmarked_nbs, val))
            pb(stack_a, stack_b);
        else
        {
            if (stack_b->size > 2 
                && *(stack_b->top->value) < *(stack_b->top->next->value) 
                && *(stack_b->top->value) < *(stack_b->top->next->next->value))
                rr(stack_a, stack_b);
            else
                ra(stack_a);
        }
        i++;
    }
}

t_unmarked  *find_unmarked_nums(t_unmarked *unmarked_nbs, int *flags, int *arr_ord, int size)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < size)
    {
        if (flags[i] != 1)
        {
            unmarked_nbs->unmarked_nums[j] = arr_ord[i];
            j++;
        }
        i++;
    }
    unmarked_nbs->unmarked_size = j;
    return (unmarked_nbs);
}

t_unmarked  *allocate_and_fill_unmarked(int *flags, int *arr_ord, int size)
{
    t_unmarked *unmarked_nbs;
    //(malloc in func, need to be free)

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

void    rotate_min_to_top(t_stack *stack_a, int min)
{
    int index;
    int cost;

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

void    push_swap(t_stack *stack_a, t_stack *stack_b)
{
    int *flags;
    int *arr_ord;
    t_unmarked *unmarked_nbs;
    int min;

    arr_ord = stack_mapping_arr_ord(stack_a);
    flags = stack_mapping_arr_flags(stack_a);
    unmarked_nbs = allocate_and_fill_unmarked(flags, arr_ord, stack_a->size);
    // print_arr(unmarked_nbs->unmarked_nums, unmarked_nbs->unmarked_size);
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
