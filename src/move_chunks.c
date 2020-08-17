/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amargy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:03:04 by amargy            #+#    #+#             */
/*   Updated: 2020/02/27 19:19:07 by amargy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_go_b(t_ps *p)
{
	while (p->pas != p->top_a && p->pas != p->i_last + 1)
	{
		if ((p->pas - p->top_a) - (p->i_last - p->pas) > 1)
		{
			exec_rra_rrb(p->top_a, p->a, p->i_last);
			create_com_node(p);
			p->tmp_c->com = strdup("rra");
			p->pas++;
		}
		else if ((p->pas - p->top_a) - (p->i_last - p->pas) <= 1)
		{
			exec_ra_rb(p->top_a, p->a, p->i_last);
			create_com_node(p);
			p->tmp_c->com = strdup("ra");
			p->pas--;
		}
	}
	exec_pa_pb(p, "a");
	create_com_node(p);
	p->tmp_c->com = strdup("pb");
}

void	b_go_a(t_ps *p)
{
	while (p->pas != p->top_b && p->pas != p->i_last + 1)
	{
		if ((p->pas - p->top_b) - (p->i_last - p->pas) > 1)
		{
			exec_rra_rrb(p->top_b, p->b, p->i_last);
			create_com_node(p);
			p->tmp_c->com = strdup("rrb");
			p->pas++;
		}
		else if ((p->pas - p->top_b) - (p->i_last - p->pas) <= 1)
		{
			exec_ra_rb(p->top_b, p->b, p->i_last);
			create_com_node(p);
			p->tmp_c->com = strdup("rb");
			p->pas--;
		}
	}
	exec_pa_pb(p, "b");
	create_com_node(p);
	p->tmp_c->com = strdup("pa");
	p->q_pa++;
}

void	move_create_chunk_b(t_ps *p)
{
	create_ch_list(&p->b_ch);
	p->b_ch->chunk = NULL;
	while (find_passenger_a(p) != -1)
		a_go_b(p);
	p->q_pa--;
}

void	move_create_chunk_a(t_ps *p)
{
	create_ch_list(&p->a_ch);
	while (find_passenger_b(p) != -1)
		b_go_a(p);
	if (p->q_pa != 0)
		b_chunks_operations(p);
}
