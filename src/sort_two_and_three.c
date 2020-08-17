/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two_and_three.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amargy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:03:47 by amargy            #+#    #+#             */
/*   Updated: 2020/02/27 19:19:37 by amargy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fuck_norme(t_ps *p, int t)
{
	if ((p->a[t] > p->a[t + 1] && p->a[t] > p->a[t + 2]
	&& p->a[t + 1] > p->a[t + 2]) || (p->a[t] > p->a[t + 1]
	&& p->a[t] < p->a[t + 2]) || (p->a[t] < p->a[t + 1]
	&& p->a[t] < p->a[t + 2] && p->a[t + 1] > p->a[t + 2]))
	{
		exec_sa_sb(p->top_a, p->a, p->i_last);
		create_com_node(p);
		p->tmp_c->com = strdup("sa");
	}
	if ((p->a[t] > p->a[t + 1] && p->a[t] > p->a[t + 2]
	&& p->a[t + 1] < p->a[t + 2]))
	{
		exec_ra_rb(p->top_a, p->a, p->i_last);
		create_com_node(p);
		p->tmp_c->com = strdup("ra");
	}
	if ((p->a[t] > p->a[t + 1] && p->a[t] > p->a[t + 2]
	&& p->a[t + 1] > p->a[t + 2]) || (p->a[t] < p->a[t + 1]
	&& p->a[t] > p->a[t + 2]))
	{
		exec_rra_rrb(p->top_a, p->a, p->i_last);
		create_com_node(p);
		p->tmp_c->com = strdup("rra");
	}
}

void	sort_three_a(t_ps *p)
{
	int t;

	t = p->top_a;
	fuck_norme(p, t);
}

void	sort_two_in_top(char *from, t_ps *p)
{
	if (from[0] == 'a')
		if (p->a[p->top_a] > p->a[p->top_a + 1])
		{
			exec_sa_sb(p->top_a, p->a, p->i_last);
			create_com_node(p);
			p->tmp_c->com = strdup("sa");
		}
}
