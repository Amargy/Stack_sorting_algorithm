/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_data2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amargy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 12:05:27 by amargy            #+#    #+#             */
/*   Updated: 2020/03/10 12:05:29 by amargy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_com_node(t_ps *p)
{
	if (p->c == NULL)
	{
		if (!(p->c = (t_c *)malloc(sizeof(t_c))))
			exit(-1);
		p->c->com = NULL;
		p->tmp_c = p->c;
		p->tmp_c->next = NULL;
	}
	else
	{
		if (!(p->tmp_c->next = (t_c *)malloc(sizeof(t_c))))
			exit(-1);
		p->tmp_c = p->tmp_c->next;
		p->tmp_c->com = NULL;
		p->tmp_c->next = NULL;
	}
}
