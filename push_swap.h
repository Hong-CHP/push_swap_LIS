#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_node
{
    int         *value;
    struct s_node *next;
    struct s_node *prev;
}               t_node;

typedef struct s_stack
{
    t_node *top;
    int     size;
}               t_stack;

typedef struct s_unmarked
{
    int *unmarked_nums;
    int unmarked_size;
}              t_unmarked;

typedef struct s_move {
    int val;
    int a_rot;
    int b_rot;
    int total_cost;
}               t_move;

void    print_arr(int *arr, int size);
void    ft_print_stack(t_stack *stack);
int     ft_strlen(char *str);
int     is_space(char c);
int     ft_split_needed(int ac, char *av[]);
char	*ft_strdup(char *src);
char    *ft_strjoin(char *str_tab, int ac, char *av[]);
char    *join_before_split(int ac, char *av[]);
void	free_reverse_params(int ac, char **res);
int     count_words(char *str);
char    **ft_split(char **res, char *str);
char    **allocate_and_split(char *str);
int     is_validate_param(char *str);
int     *ft_bzero(int *s, size_t n);
int     ft_atoi(char *str);
void	get_value_init_stack(int argc, char *argv[]);
void	swap_top_two(t_stack *stack);
void	push_to_top(t_stack *stack_a, t_stack *stack_b);
void	rotate_to_top(t_stack *stack);
void    reverse_rotate(t_stack *stack);
void	swap_top_two(t_stack *stack);
void	push_to_top(t_stack *stack_a, t_stack *stack_b);
void	rotate_to_top(t_stack *stack);
void    reverse_rotate(t_stack *stack);
void    sa(t_stack *stack_a);
void    sb(t_stack *stack_b);
void    ss(t_stack *stack_a, t_stack *stack_b);
void    ra(t_stack *stack_a);
void    rb(t_stack *stack_b);
void    rr(t_stack *stack_a, t_stack *stack_b);
void    rra(t_stack *stack_a);
void    rrb(t_stack *stack_b);
void    rrr(t_stack *stack_a, t_stack *stack_b);
void    pb(t_stack *stack_b, t_stack *stack_a);
void    pa(t_stack *stack_b, t_stack *stack_a);
void    sort_two(t_stack *stack);
void    sort_three(t_stack *stack);
int     find_mins_pos_in_simple(t_stack *stack_a, int num);
int     find_shortest_from_mins(int *mins_path, int size);
void    get_arr_min_check_rotate_push(t_stack *stack_a, t_stack *stack_b, int *arr, int *mins_path);
void    easy_push_swap(t_stack *stack_a, t_stack *stack_b);
int     *creat_array_from_stack(t_stack *stack_a, int *arr);
void    get_sort_arr(int size, int *arr);
int     get_real_pos(t_stack *stack_a, int num);
int     *stack_mapping_arr_ord(t_stack *stack_a);
int     *stack_mapping_arr_flags(t_stack *stack_a);
int     *get_longest_increasing_nums(int *arr, int size);
void    push_swap(t_stack *stack_a, t_stack *stack_b);
int     is_obj_unmarked(t_unmarked *unmarked_nbs, int val);
int     ft_max(int a, int b);
int     ft_abs(int nb);
int     get_index(t_stack *stack, int val);
void    check_before(t_stack *stack_a, t_stack *stack_b, int val);
int     calc_rot_cost(int size, int index);
int     find_val_insert_place(t_stack *stack_a, int val);
int     solve_exp_case(t_stack *stack_a, int val);
void    push_swap_back(t_stack *stack_a, t_stack *stack_b, t_unmarked *unmarked_nbs);

#endif