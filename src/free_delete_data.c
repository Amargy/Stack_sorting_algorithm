/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_delete_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amargy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:02:51 by amargy            #+#    #+#             */
/*   Updated: 2020/02/27 19:18:54 by amargy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delete_value_in_chunk(t_ch_val **chunk, int val)
{
	t_ch_val *tmp1;
	t_ch_val *tmp2;

	tmp1 = *chunk;
	while (tmp1 != NULL)
	{
		if (tmp1->val == val)
		{
			if (tmp1 == *chunk)
			{
				*chunk = (*chunk)->next;
				free(tmp1);
				return ;
			}
			else
			{
				tmp2->next = tmp1->next;
				free(tmp1);
				return ;
			}
		}
		tmp2 = tmp1;
		tmp1 = tmp1->next;
	}
}

void	delete_chunk(t_ch *ch)
{
	free(ch);
	ch = NULL;
}

void	free_chunks(t_ch *ch)
{
	t_ch		*tmp;
	t_ch_val	*tmp_val;

	while (ch->back != NULL)
		ch = ch->back;
	while (ch != NULL)
	{
		tmp = ch;
		ch = ch->next;
		while (tmp->chunk != NULL)
		{
			tmp_val = tmp->chunk;
			tmp->chunk = tmp->chunk->next;
			if (tmp_val)
				free(tmp_val);
		}
		if (tmp)
			free(tmp);
	}
}

void	free_stacks(t_ps *p)
{
	if (p->a)
		free(p->a);
	if (p->b)
		free(p->b);
}

int		free_comlist_and_ret(t_ps *p)
{
	free(p->c);
	p->c = NULL;
	return (1);
}
