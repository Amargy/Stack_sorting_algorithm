/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_mid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amargy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:02:30 by amargy            #+#    #+#             */
/*   Updated: 2020/03/10 11:58:41 by amargy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_quantity_of_numbers_in_chunk(t_ch_val *chunk, t_ps *p)
{
	int			i;
	t_ch_val	*tmp;

	i = 0;
	tmp = chunk;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	p->q_val = i;
}

int		*write_temp_int_massive_a(t_ps *p, int size)
{
	int *tmp_chunk;
	int i;

	i = 0;
	if (!(tmp_chunk = (int *)malloc(sizeof(int) * size)))
		exit(-1);
	p->tmp_chunk = p->a_ch->chunk;
	while (p->tmp_chunk != NULL)
	{
		tmp_chunk[i] = p->tmp_chunk->val;
		p->tmp_chunk = p->tmp_chunk->next;
		i++;
	}
	return (tmp_chunk);
}

int		*write_temp_int_massive_b(t_ps *p, int size)
{
	int *tmp_chunk;
	int i;

	i = 0;
	if (!(tmp_chunk = (int *)malloc(sizeof(int) * size)))
		exit(-1);
	p->tmp_chunk = p->b_ch->chunk;
	while (p->tmp_chunk != NULL)
	{
		tmp_chunk[i] = p->tmp_chunk->val;
		p->tmp_chunk = p->tmp_chunk->next;
		i++;
	}
	return (tmp_chunk);
}

void	find_mid(t_ps *p, char *from)
{
	int *tmp_chunk;

	if (from[0] == 'a')
	{
		find_quantity_of_numbers_in_chunk(p->a_ch->chunk, p);
		tmp_chunk = write_temp_int_massive_a(p, p->q_val);
	}
	else
	{
		find_quantity_of_numbers_in_chunk(p->b_ch->chunk, p);
		tmp_chunk = write_temp_int_massive_b(p, p->q_val);
	}
	ft_quick_sort(tmp_chunk, 0, p->q_val - 1);
	p->mid = tmp_chunk[p->q_val / 2];
	free(tmp_chunk);
	tmp_chunk = NULL;
}
