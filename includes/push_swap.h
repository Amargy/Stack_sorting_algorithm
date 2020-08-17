/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amargy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:51:20 by amargy            #+#    #+#             */
/*   Updated: 2020/03/10 12:02:45 by amargy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct			s_c
{
	char				*com;
	struct s_c			*next;
}						t_c;

typedef struct			s_ch_val
{
	int					val;
	struct s_ch_val		*next;
}						t_ch_val;

typedef struct			s_ch
{
	struct s_ch_val		*chunk;
	struct s_ch			*next;
	struct s_ch			*back;
}						t_ch;

typedef struct			s_ps
{
	int					*a;
	int					*b;
	t_c					*c;
	t_c					*tmp_c;
	t_ch				*a_ch;
	t_ch				*b_ch;
	int					top_a;
	int					top_b;
	int					i_last;
	int					gnl_sec_iter;
	long long			overflow;
	int					mid;
	int					pas;
	int					q_val;
	int					q_pa;
	int					max;
	int					first_iter;
	t_ch_val			*tmp_chunk;
	char				*cur_com;
	int					ifnocom;
	int					i;
	int					start_number;
	int					find_number;
	int					find_minus;
	int					*tmp_stack;
}						t_ps;

int						is_valid_write_in_stack(char **argv, t_ps *p);
int						com_valid_and_write(t_ps *p);
int						check_arg(char **argv, t_ps *p);
void					free_stacks_and_com(t_ps *p);
int						cur_com_valid(char *cur_com);
t_ps					*create_main_struct();
void					create_stacks(t_ps *p);
void					processing_commands(t_ps *p);
void					execute_command(t_ps *p, char *cur_com);
void					exec_sa_sb(int top, int *stack, int i_last);
void					exec_ss(t_ps *p);
void					exec_pa_pb(t_ps *p, char *from);
void					exec_ra_rb(int top, int *stack, int i_last);
void					exec_rr(t_ps *p);
void					exec_rra_rrb(int top, int *stack, int i_last);
void					exec_rrr(t_ps *p);
int						check_result(t_ps *p);
void					create_ch_list(t_ch **ch);
void					ft_quick_sort(int *ser, int start, int end);
void					quick_sort_swap(int *a, int *b);
int						partition(int *ser, int low, int high);
void					find_mid(t_ps *p, char *from);
int						find_passenger_a(t_ps *p);
int						find_passenger_b(t_ps *p);
void					delete_chunk(t_ch *ch);
void					a_go_b(t_ps *p);
void					b_go_a(t_ps *p);
void					move_create_chunk_b(t_ps *p);
void					move_create_chunk_a(t_ps *p);
void					sort_three_a(t_ps *p);
void					sort_three_b(t_ps *p);
void					sort_two_in_top(char *from, t_ps *p);
void					b_chunks_operations(t_ps *p);
void					a_chunks_operations(t_ps *p);
int						check_sort(int *chunk, int last);
void					sort_chunks(t_ps *p);
void					create_main_chunk(t_ps *p);
void					create_com_node(t_ps *p);
void					algo(t_ps *p);
void					write_commands(t_ps *p);
int						main(int argc, char **argv);
void					intermediate_sort(t_ps *p, char *where);
void					find_sort_series(t_ps *p);
int						*write_temp_int_massive_a(t_ps *p, int size);
int						*write_temp_int_massive_b(t_ps *p, int size);
void					delete_value_in_chunk(t_ch_val **chunk, int val);
void					add_value_in_chunk(t_ch_val **val_node, int val);
void					create_val_list(t_ch_val **val_node);
void					find_quantity_of_numbers_in_chunk
						(t_ch_val *chunk, t_ps *p);
void					check_max(t_ps *p);
int						check_duplicate(t_ps *p);
void					f_atoi(const char *str, t_ps *p);
int						check_arg_terminator(char **argv);
void					ft_ero(void *s, size_t n);
void					free_chunks(t_ch *ch);
int						free_comlist_and_ret(t_ps *p);
void					fuck_norme(t_ps *p, int t);
int						pars_arg(char *arg, t_ps *p);
int						check_overflow_and_take_numb(char *arg,
						t_ps *p, int count_number);
int						walk_along_arg_and_check_long_long(char *arg, t_ps *p);
void					free_stacks(t_ps *p);
int						walk_along_arg2(char *arg, t_ps *p);

#endif
