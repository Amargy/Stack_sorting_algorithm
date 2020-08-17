/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amargy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:02:20 by amargy            #+#    #+#             */
/*   Updated: 2020/03/10 12:00:06 by amargy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_ch_list(t_ch **ch)
{
	t_ch *tmp;

	if (*ch == NULL)
	{
		if (!(*ch = (t_ch *)malloc(sizeof(t_ch))))
			exit(-1);
		(*ch)->chunk = NULL;
		(*ch)->next = NULL;
		(*ch)->back = NULL;
	}
	else
	{
		if (!((*ch)->next = (t_ch *)malloc(sizeof(t_ch))))
			exit(-1);
		tmp = *ch;
		*ch = (*ch)->next;
		(*ch)->chunk = NULL;
		(*ch)->back = tmp;
		(*ch)->next = NULL;
	}
}

void	create_main_chunk(t_ps *p)
{
	int			i;
	t_ch_val	*tmp;

	i = -1;
	create_ch_list(&p->a_ch);
	create_val_list(&p->a_ch->chunk);
	tmp = p->a_ch->chunk;
	tmp->val = p->a[++i];
	while (++i <= p->i_last)
	{
		create_val_list(&tmp);
		tmp->val = p->a[i];
	}
}

void	create_val_list(t_ch_val **val_node)
{
	if (*val_node == NULL)
	{
		if (!(*val_node = (t_ch_val *)malloc(sizeof(t_ch_val))))
			exit(-1);
		(*val_node)->next = NULL;
	}
	else
	{
		if (!((*val_node)->next = (t_ch_val *)malloc(sizeof(t_ch_val))))
			exit(-1);
		*val_node = (*val_node)->next;
		(*val_node)->next = NULL;
	}
}

void	create_stacks(t_ps *p)
{
	int i;

	i = 0;
	p->top_a = 0;
	p->top_b = p->i_last + 1;
	if (!(p->a = (int *)malloc(sizeof(int) * (p->i_last + 1))))
		exit(-1);
	if (!(p->b = (int *)malloc(sizeof(int) * (p->i_last + 1))))
		exit(-1);
	while (i <= p->i_last)
	{
		p->a[i] = p->tmp_stack[i];
		i++;
	}
}

t_ps	*create_main_struct(void)
{
	t_ps	*p;

	if (!(p = (t_ps *)malloc(sizeof(t_ps))))
		exit(-1);
	p->ifnocom = 0;
	p->i_last = 0;
	p->a_ch = NULL;
	p->b_ch = NULL;
	p->c = NULL;
	p->max = -2147483648;
	p->first_iter = 0;
	p->gnl_sec_iter = 0;
	if (!(p->tmp_stack =
	(int *)malloc(sizeof(int) * 214748364)))
		exit(-1);
	p->cur_com = NULL;
	p->find_number = 0;
	p->start_number = 0;
	p->i = 0;
	p->find_minus = 0;
	return (p);
}
