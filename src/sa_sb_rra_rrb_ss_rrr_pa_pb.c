/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_rra_rrb_ss_rrr_pa_pb.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amargy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:03:39 by amargy            #+#    #+#             */
/*   Updated: 2020/02/27 19:19:21 by amargy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_sa_sb(int top, int *stack, int i_last)
{
	int tmp;

	if (top < i_last)
	{
		tmp = stack[top];
		stack[top] = stack[top + 1];
		stack[top + 1] = tmp;
	}
}

void	exec_pa_pb(t_ps *p, char *from)
{
	if (from[0] == 'a')
	{
		if (p->top_a >= 0 && p->top_a <= p->i_last)
		{
			p->top_b--;
			p->b[p->top_b] = p->a[p->top_a];
			p->top_a++;
		}
	}
	else if (from[0] == 'b')
	{
		if (p->top_b >= 0 && p->top_b <= p->i_last)
		{
			p->top_a--;
			p->a[p->top_a] = p->b[p->top_b];
			p->top_b++;
		}
	}
}

void	exec_rra_rrb(int top, int *stack, int i_last)
{
	int tmp;
	int tmp2;
	int tmp_last_value;
	int tmp_top_i;

	if (top >= 0 && top < i_last)
	{
		tmp_last_value = stack[i_last];
		tmp2 = stack[top];
		tmp_top_i = top;
		while (top < i_last)
		{
			tmp = tmp2;
			top++;
			tmp2 = stack[top];
			stack[top] = tmp;
		}
		stack[tmp_top_i] = tmp_last_value;
	}
}

void	exec_ss(t_ps *p)
{
	exec_sa_sb(p->top_a, p->a, p->i_last);
	exec_sa_sb(p->top_b, p->b, p->i_last);
}

void	exec_rrr(t_ps *p)
{
	exec_ra_rb(p->top_a, p->a, p->i_last);
	exec_ra_rb(p->top_b, p->b, p->i_last);
}
