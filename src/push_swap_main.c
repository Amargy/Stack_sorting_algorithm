/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amargy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:03:16 by amargy            #+#    #+#             */
/*   Updated: 2020/02/27 19:18:01 by amargy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_commands(t_ps *p)
{
	p->tmp_c = p->c;
	while (p->tmp_c != NULL)
	{
		ft_printf("%s\n", p->tmp_c->com);
		p->tmp_c = p->tmp_c->next;
	}
}

void	sort_chunks(t_ps *p)
{
	if (check_sort(p->a, p->i_last) && p->top_a == 0)
		return ;
	if (p->b_ch == NULL)
	{
		create_main_chunk(p);
		b_chunks_operations(p);
	}
	else
	{
		p->first_iter = 1;
		a_chunks_operations(p);
	}
	sort_chunks(p);
}

void	algo(t_ps *p)
{
	if (p->i_last > 2)
	{
		sort_chunks(p);
		return ;
	}
	if (p->i_last == 2)
		sort_three_a(p);
	else if (p->i_last == 1)
		sort_two_in_top("a", p);
}

int		main(int argc, char **argv)
{
	t_ps *p;

	if (argc >= 2)
	{
		p = create_main_struct();
		if (check_arg_terminator(argv) && check_arg(argv, p))
		{
			algo(p);
			write_commands(p);
			free_stacks_and_com(p);
		}
		else
		{
			free_stacks_and_com(p);
			write(1, "Error\n", 6);
		}
	}
	return (0);
}
