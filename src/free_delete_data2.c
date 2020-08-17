/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_delete_data2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amargy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 12:17:07 by amargy            #+#    #+#             */
/*   Updated: 2020/03/10 12:17:43 by amargy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stacks_and_com(t_ps *p)
{
	free_stacks(p);
	free(p->tmp_stack);
	while (p->c != NULL)
	{
		p->tmp_c = p->c;
		p->c = p->c->next;
		if (p->tmp_c->com != NULL)
		{
			free(p->tmp_c->com);
			p->tmp_c->com = NULL;
		}
		if (p->tmp_c != NULL)
		{
			free(p->tmp_c);
			p->tmp_c = NULL;
		}
	}
	if (p->a_ch != NULL)
		free_chunks(p->a_ch);
	if (p->b_ch != NULL)
		free_chunks(p->b_ch);
	if (p->cur_com != NULL)
		free(p->cur_com);
	free(p);
}
