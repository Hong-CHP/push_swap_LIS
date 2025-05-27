#include "push_swap.h"

int check_if_unsort(t_stack *stack_a)
{
    t_node *cur;

    cur = stack_a->top;
    while (cur->next)
    {
        if (*(cur->value) > *(cur->next->value))
            return(1);
        cur = cur->next;
    }
    return (0);
}

int *creat_array_from_stack(t_stack *stack_a, int *arr)
{
    t_node *cur;
    int i;

    cur = stack_a->top;
    i = 0;
    while (cur)
    {
        arr[i++] = *(cur->value);
        cur = cur->next;
    }
    return (arr);
}

int    *stack_mapping_arr_ord(t_stack *stack_a)
{
    int *arr;

    arr = malloc(sizeof(int) * stack_a->size);
    if (!arr)
        return (NULL);
    arr = creat_array_from_stack(stack_a, arr);
    return (arr);
}

int    *stack_mapping_arr_flags(t_stack *stack_a)
{
    int *arr;
    int *flags;
    
    arr = malloc(sizeof(int) * stack_a->size);
    if (!arr)
        return (NULL);
    arr = creat_array_from_stack(stack_a, arr);
    flags = get_longest_increasing_nums(arr, stack_a->size);
    free(arr);
    return (flags);
}

void    get_sort_arr(int size, int *arr)
{
    int temp;
    int i;
    int j;

    i = 0;
    while (i < size - 1)
    {
        j = i + 1;
        while (j < size)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            j++;
        }
        i++;
    }
}