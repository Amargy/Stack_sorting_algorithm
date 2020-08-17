/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amargy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:01:41 by amargy            #+#    #+#             */
/*   Updated: 2020/02/27 19:15:56 by amargy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_max(t_ps *p)
{
	while (p->a[p->i_last] < p->max)
	{
		exec_rra_rrb(p->top_a, p->a, p->i_last);
		create_com_node(p);
		p->tmp_c->com = strdup("rra");
	}
}

int		check_sort(int *chunk, int last)
{
	int i;

	i = 0;
	while (i != last)
	{
		if (chunk[i] > chunk[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	b_chunks_operations(t_ps *p)
{
	while (!(check_sort(&p->a[p->top_a], p->i_last))
	&& !(p->q_pa == 2 || p->q_pa == 1))
	{
		find_mid(p, "a");
		if (p->q_val != 2 && p->q_val != 1)
			move_create_chunk_b(p);
		else
			break ;
	}
	if (p->first_iter == 1)
		check_max(p);
	sort_two_in_top("a", p);
	p->q_pa = 0;
}

void	a_chunks_operations(t_ps *p)
{
	while (p->b_ch != NULL)
	{
		if (p->b_ch->chunk == NULL)
		{
			delete_chunk(p->b_ch);
			p->b_ch = p->b_ch->back;
			if (p->b_ch == NULL)
				return ;
		}
		find_mid(p, "b");
		move_create_chunk_a(p);
	}
}
