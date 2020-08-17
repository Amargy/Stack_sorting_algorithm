/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amargy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:03:30 by amargy            #+#    #+#             */
/*   Updated: 2020/02/27 19:18:26 by amargy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_ra_rb(int top, int *stack, int i_last)
{
	int tmp;
	int tmp2;
	int tmp_first_value;
	int tmp_i_last;

	if (top >= 0 && top < i_last)
	{
		tmp_first_value = stack[top];
		tmp2 = stack[i_last];
		tmp_i_last = i_last;
		while (i_last > top)
		{
			tmp = tmp2;
			i_last--;
			tmp2 = stack[i_last];
			stack[i_last] = tmp;
		}
		stack[tmp_i_last] = tmp_first_value;
	}
}

void	exec_rr(t_ps *p)
{
	exec_ra_rb(p->top_a, p->a, p->i_last);
	exec_ra_rb(p->top_b, p->b, p->i_last);
}
