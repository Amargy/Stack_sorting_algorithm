/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_value_to_send_it.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amargy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:02:42 by amargy            #+#    #+#             */
/*   Updated: 2020/02/27 19:17:35 by amargy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_value_in_chunk(t_ch_val **val_node, int val)
{
	t_ch_val *tmp;

	if (*val_node == NULL)
	{
		create_val_list(&(*val_node));
		(*val_node)->val = val;
	}
	else
	{
		tmp = *val_node;
		while (tmp->next != NULL)
			tmp = tmp->next;
		create_val_list(&tmp);
		tmp->val = val;
	}
}

int		find_passenger_b(t_ps *p)
{
	p->pas = p->top_b - 1;
	while (++p->pas <= p->i_last)
	{
		if (p->b[p->pas] > p->mid
		|| ((p->q_val == 2 || p->q_val == 1) && p->b[p->pas] == p->mid))
		{
			add_value_in_chunk(&p->a_ch->chunk, p->b[p->pas]);
			delete_value_in_chunk(&p->b_ch->chunk, p->b[p->pas]);
			return (p->pas);
		}
	}
	return (-1);
}

int		find_passenger_a(t_ps *p)
{
	p->pas = p->top_a - 1;
	while (++p->pas <= p->i_last)
	{
		if (p->a[p->pas] < p->mid
		|| ((p->q_val == 2 || p->q_val == 1) && p->a[p->pas] == p->mid))
		{
			add_value_in_chunk(&p->b_ch->chunk, p->a[p->pas]);
			delete_value_in_chunk(&p->a_ch->chunk, p->a[p->pas]);
			return (p->pas);
		}
	}
	return (-1);
}
